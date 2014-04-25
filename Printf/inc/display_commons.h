
#ifndef __DISPLAY_COMMONS_H__
#define __DISPLAY_COMMONS_H__


/*
**Common functions used by different displays procedures
*/

/*
** Writes width - done  chars
** The char written depends on the attribut
*/
int			filled_width(int width, int done , int attribut, int nb);
int			treat_attributes_num(int att, int precision);
int			treat_attributes_str(int att);
char			*add_precision(char *str, int precision);
char			*select_base(char conv);
#endif
