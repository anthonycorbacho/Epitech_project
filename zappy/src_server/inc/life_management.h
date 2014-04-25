/*
** life_management.h for life in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Wed Mar 24 10:32:33 2010 mathieu1 lornac
** Last update Wed Mar 24 11:40:20 2010 damien1 coppel
*/

#ifndef __LIFE_MANAGEMENT_H__
#define __LIFE_MANAGEMENT_H__

#include <sys/time.h>

#define FOOD_SPAN (3 * 42)

void	set_next_meal(struct timeval *next_meal);
void	check_life();

#endif /*__LIFE_MANAGEMENT_H__*/
