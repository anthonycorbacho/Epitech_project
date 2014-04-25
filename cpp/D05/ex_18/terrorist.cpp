//
// terrorist.cpp for terrorist in /home/Anthony/Epitech/piscine/cpp/24h/ex_16
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 16:49:40 2010 anthony1 corbacho
// Last update Fri May  7 17:31:46 2010 anthony1 corbacho
//

#include	<iostream>
#include	<string>
#include	"terrorist.h"

void	Terrorist::setGun(std::string String)
{
  this->_gun = String;
}

void	Terrorist::setName(std::string String)
{
  this->_name = String;
}

std::string	Terrorist::getGun()
{
  return (this->_gun);
}

std::string	Terrorist::getName()
{
  return (this->_name);
}
