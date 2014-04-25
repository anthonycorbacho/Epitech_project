
#ifndef __TERMCAPS_H__
#define __TERMCAPS_H__

typedef struct	s_caps_str
{
  char		*cm;		
  char		*clr_scr;	/*Clear screen*/
  char		*cr;		/*Carriage return*/
  char		*dl;		/*Deltes a line*/
  char		*vi;		/*Cursor off*/
  char		*ve;		/*Cursor on*/
  char		*up;		/*Cursor up*/
  char		*doi;		/*Cursor down*/
}		t_caps_str;

char			*xtgetstr(char *cap, char **area);
t_caps_str		*get_variables(char **area, char **term, char bp[1024]);
int			my_outc(int c);
t_caps_str		*retrieve_vars(t_caps_str *vars);
#endif
