//
// ex_0.cpp for ex_0 in /home/corbac_b/work/piscine/cpp/D03A/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May  5 20:13:49 2010 anthony1 corbacho
// Last update Wed May  5 22:22:07 2010 anthony1 corbacho
//

#include	"ex_0.h"

// Card
Cluedo::Card::Card()
{

}

Cluedo::Card::~Card()
{
  
}

bool	Cluedo::Card::IsPartOfTheCrime() const
{
  return (this->_isPartOfTheCrime);
}

//Weapon
Cluedo::Weapon::Weapon(Weapon::Name name, bool bearsFingerprints)
{
  if (Cluedo::Weapon::PartOfTheCrime ==
      name)
    _isPartOfTheCrime = 1;
  else
    _isPartOfTheCrime = 0;
  _emp = bearsFingerprints;
}

Cluedo::Weapon::~Weapon()
{
  
}

bool	Cluedo::Weapon::BearsFingerprints() const
{
  return (this->_emp);
}

//Suspect
Cluedo::Suspect::Suspect(Suspect::Name name, bool isLying)
{
  if (Cluedo::Suspect::PartOfTheCrime ==
      name)
    _isPartOfTheCrime = 1;
  else
    _isPartOfTheCrime = 0;
  _lying = isLying;
}

Cluedo::Suspect::~Suspect()
{

}


bool        Cluedo::Suspect::IsLying() const
{
  return (this->_lying);
}

//Room
Cluedo::Room::Room(Cluedo::Room::Name name, bool hasSecretPassage)
{
  if (Cluedo::Room::PartOfTheCrime == name)
    _isPartOfTheCrime = 1;
  else
    _isPartOfTheCrime = 0;
  _pass = hasSecretPassage;
}

Cluedo::Room::~Room()
{

}

bool	Cluedo::Room::HasSecretPassage() const
{
  return (this->_pass);
}

//Game
bool	Cluedo::Game::CaseSolved(Weapon* w[], Suspect* s[],
				 Room* r[])
{
  bool	bgame = 0;
  bool	broom = 0;
  bool	bsuspect = 0;

  for (int i = 0; w[i] ; i++)
    {
      if (w[i]->IsPartOfTheCrime() == 1)
	bgame = 1;
    }
  for (int y = 0; s[y] ; y++)
    {
      if (s[y]->IsPartOfTheCrime() == 1)
	bsuspect = 1;
    }
  for (int z = 0; r[z] ; z++)
    {
      if (r[z]->IsPartOfTheCrime() == 1)
	broom = 1;
    }
  if (bgame == broom == bsuspect == 1)
    return (1);
  return (0);
}
