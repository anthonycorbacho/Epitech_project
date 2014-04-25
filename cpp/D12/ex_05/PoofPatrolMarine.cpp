//
// PoofPatrolMarine.cpp for PoofPatrolMarine in /media/Vash/D12/ex_05
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 17:02:09 2010 anthony1 corbacho
// Last update Fri May 14 17:02:50 2010 anthony1 corbacho
//

#include "PoofPatrolMarine.h"

PoofPatrolMarine::PoofPatrolMarine()
{
  outfit = NULL;
}

PoofPatrolMarine::~PoofPatrolMarine()
{
}

void			PoofPatrolMarine::describeOutfit()
{
  if (outfit != NULL)
    {
      std::cout
	<< "Alors, par-dessus mon petit ensemble en satin, je porte : "
	<< outfit->describe()
	<< std::endl;
    }
  else
    {
      std::cout
	<< "Hihihihihi, je suis tellement sexy tout nu que les ennemis ne pourront pas me faire de mal !"
	<< std::endl;
    }
}

void			PoofPatrolMarine::setOutfit(PoofPatrolArmor *armor)
{
  outfit = armor;
}

