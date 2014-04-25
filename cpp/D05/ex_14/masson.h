/*
** masson.h for masson in /home/Anthony/Epitech/piscine/cpp/24h/ex_14
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 15:41:31 2010 anthony1 corbacho
** Last update Fri May  7 17:39:54 2010 anthony1 corbacho
*/

#ifndef __MASSON_H__
#define __MASSON_H__

#include	"dessler.h"

class masson
{
 private:
  mutable short gun;
 public:
  friend	class dessler;
};

#endif /*__MASSON_H__*/
