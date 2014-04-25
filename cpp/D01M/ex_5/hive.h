/*
** hive.h for hive.h in /home/corbac_b/work/piscine/cpp/D01M/ex_5
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 13:54:11 2010 anthony1 corbacho
** Last update Mon May  3 14:11:25 2010 anthony1 corbacho
*/

#ifndef		__HIVE_H__
#define		__HIVE_H__

namespace	creature
{
  struct	hive
  {
    float	foodQuantity;
    float	antQuantity;
    float	hiveScent;
    int		populate(float);
  };

  int		hive::populate(float give=0)
  {
    if (give > 0)
      {
	if (foodQuantity > 25)
	  hiveScent += give;
	return (1);
      }
    return (0);
  }
}

#endif		//__HIVE_H__
