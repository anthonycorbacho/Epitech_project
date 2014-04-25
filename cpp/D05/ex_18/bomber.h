/*
** bomber.h for bomber in /home/Anthony/Epitech/piscine/cpp/24h/ex_17
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 17:29:52 2010 anthony1 corbacho
** Last update Fri May  7 18:47:35 2010 anthony1 corbacho
*/

#ifndef __BOMBER_H__
#define __BOMBER_H__

#include	"terrorist.h"

class           Bomber : public Terrorist
{
 private:
  bool  _bomb;

 public:
  void  setBomb();
  void  kaboom();
};

#endif /*__BOMBER_H__*/
