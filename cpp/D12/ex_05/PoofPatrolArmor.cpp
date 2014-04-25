//
// PoofPatrolArmor.cpp for PoofPatrolArmor in /media/Vash/D12/ex_05
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 17:00:13 2010 anthony1 corbacho
// Last update Fri May 14 17:00:15 2010 anthony1 corbacho
//

#include "PoofPatrolArmor.h"

PoofPatrolArmor::PoofPatrolArmor(std::string const &desc)
{
  description = desc;
}

PoofPatrolArmor::~PoofPatrolArmor()
{
}

void			PoofPatrolArmor::assemble(PoofPatrolArmor *armor)
{
  other = armor;
}

std::string		PoofPatrolArmor::describe() const
{
  std::string		result = description;

  if (other != NULL)
    result = result + ", " + other->describe();
  return (result);
}
