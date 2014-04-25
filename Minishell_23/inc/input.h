
#ifndef __INPUT_H__
#define __INPUT_H__

typedef struct  s_func_pt
{
  char          *value;
  char		*name;
  void		(*func_pt)();
}               t_func_pt;

/*
** Sets the value of the cursor if c != 0
** Returns the cursor value
*/
int			cursor(int c);

/*
** Returns the line address if NULL
** Sets it to the specified value otherwise
*/
char			*command_line(char *s);

/*
** Returns the command
*/
char			*get_next_command(const int fd);

/*
** Displays a line in the term
*/
void			display_line(t_caps_str *vars);

/*
** Returns the func pointer correponding to the char v
** or NULL if not found
*/
int			(*get_bindkey_func(char *v))();

/*
** Inserts the content of the buffer in the line at the cursor position
*/
char			*insert_string(char *line, char buffer[10]);

char			*copy_buffer(int cursor);

void			test_and_add_bindkey(char *s);
/*
** Key actions
*/
void			key_enter();
void			key_delete();
void			key_backspace();
void			key_left();
void			key_right();
void			null_action();
void			kill_whole_line();
void			kill_line();
void			clear_screen();
void			yank();
void			null_action();
void			beginning_of_line();
void			end_of_line();

extern t_func_pt	bindkey_bank_[];

#endif
