
#ifndef __DISPLAY_INT_H__
#define __DISPLAY_INT_H__

#define HEXA_base "0123456789ABCDEF"
#define hexa_base "0123456789abcdef"
#define decimal_base "0123456789"
#define octal_base "01234567"
#define binary_base "01"

int			display_int(void *arg, t_format *format);
int			display_uint(void *arg, t_format *format);
int			display_str(void *s, t_format *format);

#endif
