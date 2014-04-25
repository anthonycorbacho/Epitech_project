

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "built_ins.h"
#include "execution.h"
#include "mysh_errors.h"
#include "preprocess.h"
#include "redirections.h"

/*
** Init the toyos values according to the specified redirection operator
*/
int		init_toyos(char **instrucs, int i, int *toyos, int *old)
{
  int		(*redir)();
  int		ret_val;

  ret_val = 1;
  redir = NULL;
  if (instrucs[i + 1] && (redir = get_redirec(instrucs[i + 1])))
    ret_val = redir(old, toyos, instrucs[i]);
  else
    {
      toyos[1] = old[1];
      toyos[0] = old[0];
    }
  return (ret_val);
}

/*
** Redirects the pipe
** Has to be called in a child process
** mode == 1 Dup for i + 1 instruc
** mode == 0 Dup for i - 1 instruc
*/
void		my_dup2(int mode, int toyos[2], int olds[2], int (*redir)())
{
  if (mode)
    {
      if (redir == red_left)
	xdup2(toyos[0], olds[0]);
      else
	xdup2(toyos[0], 0);
    }
  else
    {
      if (redir == red_left)
	xdup2(toyos[0], 0);
      xdup2(olds[1], 1);
    }
}

/*
** Calls execve if necessary
*/
void		execve_call(char **instrucs, int i, t_list **my_environ)
{
  if (!(instrucs[i + 1] && get_redirec(instrucs[i + 1]) &&
	get_redirec(instrucs[i + 1]) != red_pipe))
    executer(instrucs[i], my_environ);
  else
    exit(1);
}

/*
** Waits the end of the child process
** Checks how it ended
*/
void		child_control_func(pid_t id, int toyos[2], int olds[2])
{
  int		ret_status;
  int		sig_num;

  waitpid(id, &ret_status, 0);
  if (WIFSIGNALED(ret_status))
    {
      sig_num = WTERMSIG(ret_status);
      if (sig_num == SIGSEGV)
	my_putstr_e(SEGMENTATION_FAULT_ERROR);
      else if (sig_num == SIGBUS)
	my_putstr_e(BUS_ERROR);
      else if (sig_num == SIGFPE)
	my_putstr_e(FPE_ERROR);
      else if (sig_num == SIGILL)
	my_putstr_e(ILL_INSTR_ERROR);
    }
  xclose(olds[1]);
  xclose(toyos[0]);
}

/*
** Executes the instructions with the redirections
*/
int		create_pipes_and_exec(char **ins, int i, t_list **env, int *old)
{
  int		toyos[2];
  pid_t		id;
  int		(*redir)();
  int		bt_in;

  if (!init_toyos(ins, i, toyos, old))
    return (0);
  if (ins[i + 1])
    create_pipes_and_exec(ins, i + 1, env, toyos);
  bt_in = exec_built_in(ins[i], env);
  if (!bt_in && !(redir = get_redirec(ins[i])))
    {
      if ((id = fork()) == 0)
	{
	  if (ins[i + 1] && (redir = get_redirec(ins[i + 1])))
	    my_dup2(1, toyos, old, redir);
	  if (i > 0 && (redir = get_redirec(ins[i - 1])))
	    my_dup2(0, toyos, old, redir);
	  execve_call(ins, i,env);
	}
      else
	{
	  if (!ins[i + 1])
	    toyos[0] = 0;
	  child_control_func(id, toyos, old);
	}
    }
  return (bt_in == -1);
}
