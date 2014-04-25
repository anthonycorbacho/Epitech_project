/*
** ant.h for ant.h in /home/corbac_b/work/piscine/cpp/D01M/ex_4
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 13:29:12 2010 anthony1 corbacho
** Last update Mon May  3 13:50:38 2010 anthony1 corbacho
*/

#ifndef		__ANT_H__
#define		__ANT_H__

#include	"map.h"

namespace	creature
{
  struct	ant
  {
    float	mandibule;
    float	antenna;
    float	head;
    float	age;
    item::food	food;
    float	bite(item::food);
    float	bite(float);
  };

  float		ant::bite(item::food food)
  {
    food.quantity = food.quantity;
    return (42.00);
  }
  float		ant::bite(float quantity)
  {
    return (quantity);
  }
}

#endif		//__ANT_H__
