#include <stdlib.h>

#include "lstr.h"
#include "lxsys.h"
#include "termcaps.h"
#include "input.h"

/*
** Bindkey bank initialisation
*/
t_func_pt		bindkey_bank_[] = {{"\012", "key_enter", key_enter},
				   {"\010", "backward-delete-char", key_backspace},
				   {"\033[3~", "delete-char", key_delete},
				   {"\033[D", "key_left", key_left},
				   {"\033[C", "key_right", key_right},
				   {"\025", "kill-whole-line", kill_whole_line},
				   {"\013", "kill-line", kill_line},
				   {"\013", "yank", yank},
				   {"\014", "clear-screen", clear_screen},
				   {NULL, "beginning-of-line", beginning_of_line},
				   {NULL, "end-of-line", end_of_line},
				   {"\033[B", NULL, null_action},
				   {"\033[A", NULL, null_action},
				   {"\004", NULL, null_action},
				   {NULL, NULL, NULL}};

/*
** Modifies a bindkey
*/
int			modify_bindkey(char *shortcut, char *func)
{
  int			i;

  i = 0;
  while (bindkey_bank_[i].func_pt)
    {
      if (bindkey_bank_[i].name && !my_strcmp(bindkey_bank_[i].name, func))
	{
	  bindkey_bank_[i].value = my_strdup(shortcut);
	  return (1);
	}
      ++i;
    }
  my_putstr_e("Bindkey_error: function name error\n");
  return (0);
}

/*
** Tests if the command is a bindkey add command and adds it to the bank
*/
void			test_and_add_bindkey(char *s)
{
  char			**parse;

  if (!my_strncmp("bindkey -c", s, 10))
    {
      parse = my_str_sep(s + 10, " \t");
      if (parse && my_charpp_len(parse) == 2)
	{
	  modify_bindkey(parse[0], parse[1]);
	  xfree(parse);
	}
      else
	my_putstr_e("\n Bindkey use: bindkey -c shortcut func_name");
      s[0] = 0;
    }
}

/*
** Goes to the beginning of the line
*/
void			beginning_of_line()
{
  cursor(0);
}

/*
** Goes to the end of the line
*/
void			end_of_line()
{
  cursor(my_strlen(command_line(NULL)) + 1);
}
