/*
** Janitor.h for Janitor in /home/Anthony/Epitech/piscine/cpp/12h/ex_02
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 12:46:15 2010 anthony1 corbacho
** Last update Fri May 14 13:09:41 2010 anthony1 corbacho
*/

#ifndef __JANITOR_H__
#define __JANITOR_H__


#include <iostream>
#include <string>
#include "Guard.h"

class		Janitor : public Guard
{

 public:
  Janitor(std::string const&);
  ~Janitor();
  void		inspect(Room const*) const;

 private:
  std::string	_name;
};

#endif /*__JANITOR_H__*/
