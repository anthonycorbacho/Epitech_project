//
// Room.cpp for Room in /home/Anthony/Epitech/piscine/cpp/12h/ex_02
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 12:28:41 2010 anthony1 corbacho
// Last update Fri May 14 13:23:33 2010 anthony1 corbacho
//

#include "Room.h"
//#include "Guard.h"


Room::Room(std::string const &name)
{
  _name = name;
  _object = new std::list<std::string>;
}

Room::~Room()
{
}

std::list<std::string> const&	Room::getObjects() const
{
  return *_object;
}

std::string const&		Room::getName() const
{
  return this->_name;
}

void				Room::addObject(std::string const& object)
{
  this->_object->push_back(object);
}

void				Room::allowToEnter(Guard* guardian)
{
  guardian->_auth = 1;
  guardian->inspect(this);
  guardian->_auth = 0;
}
