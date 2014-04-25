//
// Alcohol.cpp for Alcohol in /home/corbac_b/work/piscine/cpp/D02/ex_5
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 18:52:02 2010 anthony1 corbacho
// Last update Tue May  4 23:39:45 2010 anthony1 corbacho
//

#include	"values.h"
#include	"Alcohol.h"

Alcohol::Alcohol()
{
}

Alcohol::~Alcohol()
{
}

int		&Alcohol::getAvailebleAlcohol()
{
  return (this->_Unit);
}

int	Alcohol::_Unit = InitialAlcoholAvailable;
