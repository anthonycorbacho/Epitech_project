//
// Knight.cpp for Knight in /home/Anthony/Epitech/piscine/cpp/12h/ex_01
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 21:54:52 2010 anthony1 corbacho
// Last update Fri May 14 12:12:26 2010 anthony1 corbacho
//

#include "Knight.h"
#include <iostream>
#include <string>

Knight::~Knight()
{
}

Knight::Knight(std::string const& armor, int cosmos, std::string const& name)
{
  _armorType = armor;
  _cosmos = cosmos;
  _poweredUp = 0;
  _name = name;
}

void		Knight::attack(std::string const& name, int cosmosConsumed)
{
  if (_cosmos - cosmosConsumed >= 0)
    {
      _cosmos -= cosmosConsumed;
      std::cout << _name << " : " << name  << std::endl;
    }
  else
    std::cout << _name << ": not enough cosmos"  << std::endl;
}

int		Knight::getCosmos() const
{
  return this->_cosmos;
}

std::string	Knight::getName() const
{
  return this->_name;
}

std::string	Knight::getArmor() const
{
  return this->_armorType;
}

std::ostream&		operator<< (std::ostream& o, Knight& k)
{
  o << "Knight " << k.getName() << " Armor : " << k.getArmor() << " Cosmos : " << k.getCosmos();
  return o;
}

Stats			*Knight::powerUp(std::string const &armor, int cosmos)
{
  Stats			*s = new Stats(_armorType, _cosmos);

  _armorType = armor;
  _cosmos = cosmos;
  return (s);
}

void			Knight::powerDown(Stats *s)
{
  if (s != NULL && _cosmos <= 0)
    {
      _armorType = s->armor;
      _cosmos = s->cosmos;
      std::cout << "Used all cosmos, reverting to previous state" << std::endl;
    }
}
