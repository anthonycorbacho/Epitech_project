/*
** PoofPatrolMarine.h for PoofPatrolArmor in /media/Vash/D12/ex_05
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 17:01:28 2010 anthony1 corbacho
** Last update Fri May 14 17:01:58 2010 anthony1 corbacho
*/

#ifndef		__POOFPATROLMARINE_H__
#define		__POOFPATROLMARINE_H__

#include <iostream>
#include <string>
#include "PoofPatrolArmor.h"
class		PoofPatrolMarine
{
 public:
  PoofPatrolMarine();
  ~PoofPatrolMarine();
 
  void			setOutfit(PoofPatrolArmor *armor);
  void			describeOutfit();

 private:
  PoofPatrolArmor	*outfit;
};
#endif		// __POOFPATROLMARINE_H__
