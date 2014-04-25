/*
** kim.h for kim in /home/Anthony/Epitech/piscine/cpp/24h/ex_09
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 13:55:01 2010 anthony1 corbacho
** Last update Fri May  7 14:00:32 2010 anthony1 corbacho
*/

#ifndef __KIM_H__
#define __KIM_H__

#include "human.h"
#include "terry.h"
#include "jack.h"

class		kim : virtual public human, virtual public jack, virtual public terry
{
 public:
  kim();
};

#endif /*__KIM_H__*/
