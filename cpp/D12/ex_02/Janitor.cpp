//
// Janitor.cpp for Janitor in /home/Anthony/Epitech/piscine/cpp/12h/ex_02
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 12:46:24 2010 anthony1 corbacho
// Last update Fri May 14 13:22:14 2010 anthony1 corbacho
//

#include <iostream>
#include <string>
#include "Janitor.h"
#include "Guard.h"

Janitor::Janitor(std::string const& name)
{
  _name = name;
  _auth = 0;
}

Janitor::~Janitor()
{
}

void		Janitor::inspect(Room const* room) const
{
  if (this->_auth == 1)
    {
      std::cout << this->_name << " inspects " << room->getName() << " :" << std::endl;
      
      std::list<std::string>objects = room->getObjects();
      std::list<std::string>::iterator    it = objects.begin();
      std::list<std::string>::iterator    ite = objects.end();

      for (; it != ite; ++it)
	std::cout << *it << std::endl;
    }
}
