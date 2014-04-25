/*
** time_management.h for zappy in /home/damien/work_local/my_zappy/src_server
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:17:07 2010 damien1 coppel
** Last update Wed Mar 24 13:58:42 2010 damien1 coppel
*/

#ifndef __TIME_MANAGEMENT_H__
#define __TIME_MANAGEMENT_H__

#include <sys/time.h>

/*
** Add time_to_add to the struct tv
*/
void	add_time(struct timeval *tv, int time_to_add);

/*
** Return true if the time is reach
*/
int	time_is_reach(struct timeval *time);

void	check_time_and_answer();

#endif /* __TIME_MANAGEMENT_H__ */
