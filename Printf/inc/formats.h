
#ifndef __T_FORMATS_H__
#define __T_FORMATS_H__

/*
**Format structure
*/
typedef struct s_format
{
  char		convertion;
  char		*explicite;	/*See below*/
  int		attribut;
  int		field_width;
  int		len_modif;
  int		precision;
  int		size_on_stack;
  int		(*disp_func)();
}		t_format;

/*
** explicite: NULL value if it is a regular argument
** Not null if it's a regular string
*/
#endif
