/*
** map.h for map.h in /home/corbac_b/work/piscine/cpp/D01M/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 13:02:38 2010 anthony1 corbacho
** Last update Mon May  3 13:23:09 2010 anthony1 corbacho
*/

#ifndef		__MAP_H__
#define		__MAP_H__

namespace	world
{
  struct	map
  {
    struct	quadrant
    {
      float		foodScent;
      float		hiveScent;
      float		evaporation;
      item::food	food;
    };
    struct	quadrant	grid[100];
  };
}

#endif		//__MAP_H__
