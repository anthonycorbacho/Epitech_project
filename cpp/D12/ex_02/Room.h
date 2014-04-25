/*
** Room.h for Room in /home/Anthony/Epitech/piscine/cpp/12h/ex_02
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 12:28:31 2010 anthony1 corbacho
** Last update Fri May 14 13:27:12 2010 anthony1 corbacho
*/

#ifndef __ROOM_H__
#define __ROOM_H__

#include <iostream>
#include <string>
#include <list>
#include "Guard.h"

class		Guard;

class		Room
{
 public:
  Room(std::string const &st);
  ~Room();
  std::list<std::string> const&		getObjects() const;
  std::string const&			getName() const;
  void					addObject(std::string const&);
  void					allowToEnter(Guard*);

 private:
  std::list<std::string>	*_object;
  std::string			_name;
};

#endif /*__ROOM_H__*/
