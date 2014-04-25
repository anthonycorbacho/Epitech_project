
#ifndef __ATTRIBUTS_H__
#define __ATTRIBUTS_H__

#define att_sharp 1
#define att_minus 0x2
#define att_space 0x4
#define att_plus  0x8
#define att_quote 0x10
#define att_zero  0x20

#define att_sequence "#- +'0"

/*
** attributs.c
*/
int			get_attribut(char *s);

#endif
