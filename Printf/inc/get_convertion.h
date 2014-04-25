
#ifndef		__CONVERTION__
#define		__CONVERTION__

/*
**Format operator structure
*/
typedef struct		s_convertion
{
  char			*symbols;
  char			*type;
  int			(*display_func)();
}			t_convertion;

/*
** Returns the address of the function
** corresponding to the convertion symbol
*/
int		(*get_convertion(char *s))();
int		(*get_convertion_by_type(char *s))();
#endif
