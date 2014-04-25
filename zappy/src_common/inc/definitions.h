/*
** definitions.h for def in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sat Mar 20 15:12:39 2010 mathieu1 lornac
** Last update Fri Apr 16 18:51:07 2010 thomas1 salomon
*/

#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

/*
** Define the time unit
*/
#define TIME_UNIT 10

/*
** Default life for a trantorian which enters the map
*/
#define DEFAULT_LIFE 10

/*
** Simple 2d position
*/
typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

/*
** Message size
*/
#define MESS_MAX_SIZE 1024

/*
** Number of rocks
*/
#define NB_ROCKS 6

/*
** Resources indexes
*/
typedef enum ee_rocks
  {
    linemate,
    deraumere,
    sibur,
    mendiane,
    phiras,
    thystame
  } e_rocks;

/*
** Name rocks
*/
extern char	*rocks_names[6];

/*
** default host
*/
#define DEFAULT_HOST "127.0.0.1"

#endif /*__DEFINITIONS_H__*/
