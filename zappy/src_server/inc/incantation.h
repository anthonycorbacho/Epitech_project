/*
** incantation.h for zappy in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Apr 12 11:21:32 2010 mathieu1 lornac
** Last update Mon Apr 12 19:03:40 2010 damien1 coppel
*/

#ifndef __INCANTATION_H__
#define __INCANTATION_H__

#define NB_INCANT 7

/*
** Incantation prerequires
*/
typedef struct	s_incantation
{
  uchar		nbp;		/*Players needed to start incantation*/
  uchar		rocks[NB_ROCKS];/*Qt of rocks needed*/
}		t_incantation;

#define INCANT_VALUES {{1, {1, 0, 0, 0, 0, 0}},\
		 {2, {1, 1, 1, 0, 0, 0}},	\
		 {2, {2, 0, 1, 0, 2, 0}},	\
		 {4, {1, 1, 2, 0, 1, 0}},	\
		 {4, {1, 2, 1, 3, 0, 0}},	\
		 {6, {1, 2, 3, 0, 1, 0}},	\
		 {6, {2, 2, 2, 2, 2, 1}}}

/*
** Returns 1 if the incantation is possible
** 0 otherwise
*/
int		incantation_possible(t_client *cl);

#endif /*__INCANTATION_H__*/
