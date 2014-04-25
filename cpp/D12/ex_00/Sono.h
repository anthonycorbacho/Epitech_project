/*
** Sono.h for Sono.h in /home/Anthony/Epitech/piscine/cpp/12h/ex_00
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 20:20:14 2010 anthony1 corbacho
** Last update Thu May 13 21:30:12 2010 anthony1 corbacho
*/

#ifndef __SONO_H__
#define __SONO_H__

#include <stdexcept>

class		Sono
{
 private:
  unsigned int		volume;
 public:
  Sono();
  ~Sono();
  unsigned int		getVolume();
  void			setVolume(unsigned int);
};

#endif /*__SONO_H__*/
