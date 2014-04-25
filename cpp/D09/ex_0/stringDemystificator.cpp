//
// stringDemystificator.cpp for stringDemystificator in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May 11 12:38:38 2010 anthony1 corbacho
// Last update Tue May 11 14:25:33 2010 anthony1 corbacho
//

#include <iostream>
#include <string>
#include "stringDemystificator.h"

stringDemystificator::stringDemystificator()
{
  _Say = "";
}

stringDemystificator::stringDemystificator(const std::string& str)
{
  _Say = str;
}

stringDemystificator::stringDemystificator(const char* str)
{
  _Say = str;
}

stringDemystificator::stringDemystificator(const stringDemystificator& val)
{
  _Say = val.getString();
}

stringDemystificator::~stringDemystificator()
{
  _Say = "";
}

void			stringDemystificator::setString(const std::string &st)
{
  this->_Say = st;
}

std::string		stringDemystificator::getString() const
{
  return (this->_Say);
}

stringDemystificator&     stringDemystificator::operator =(const stringDemystificator& val)
{
  if (this != &val)
    this->setString(val.getString());
  return (*this);
}

void			 stringDemystificator::trim(void)
{
  size_t i;
  
  i = this->_Say.find_first_not_of(" \t");
  _Say.erase(0, i);
  i = this->_Say.find_last_not_of(" \t");
  _Say.erase(i + 1, _Say.length());
}

void			stringDemystificator::kreogize(void)
{
  if (this->_Say.length() < 6)
    this->_Say.resize(6 - this->_Say.length());
  this->_Say.replace(0, 6, "KREOG!");
  this->_Say += "KREOG!";
}

void          stringDemystificator::assemble(const std::string& str)
{
  int		i = 0;
  i = _Say.compare(str);
  if (i < 0)
    this->_Say = str + this->_Say;
  else
    this->_Say += str;
}

std::ostream&		operator <<(std::ostream& o, const stringDemystificator& val)
{
  o << val.getString();
  return (o);
}
