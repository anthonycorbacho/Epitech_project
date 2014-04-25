//
// organisation.cpp for organisation in /home/Anthony/Epitech/piscine/cpp/24h/ex_18
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 17:37:41 2010 anthony1 corbacho
// Last update Fri May  7 17:28:02 2010 anthony1 corbacho
//

#include "organisation.h"

Organisation::Organisation()
{
  this->_membersNumber = 0;
}

void		Organisation::addMember(Terrorist)
{
  this->_membersNumber++;
}

int		Organisation::getMemberNumber()
{
  return (this->_membersNumber);
}
