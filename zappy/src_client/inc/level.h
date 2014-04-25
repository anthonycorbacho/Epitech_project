/*
** level.h for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr 15 18:05:55 2010 matias1 hastaran
** Last update Thu Apr 15 18:12:25 2010 matias1 hastaran
*/

#ifndef		__LEVEL_H__
#define		__LEVEL_H__

#define NB_INCANT 7

typedef struct  s_incantation
{
  uchar		nbp;
  uchar		rocks[NB_ROCKS];
}		t_incantation;

#define INCANT_VALUES {{1, {1, 0, 0, 0, 0, 0}},\
		 {2, {1, 1, 1, 0, 0, 0}},	\
		 {2, {2, 0, 1, 0, 2, 0}},	\
		 {4, {1, 1, 2, 0, 1, 0}},	\
		 {4, {1, 2, 1, 3, 0, 0}},	\
		 {6, {1, 2, 3, 0, 1, 0}},	\
		 {6, {2, 2, 2, 2, 2, 1}}}


#endif		/* __LEVEL_H__ */
