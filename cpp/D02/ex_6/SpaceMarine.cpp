//
// SpaceMarine.cpp for SpaceMarine in /home/corbac_b/work/piscine/cpp/D02/ex_6
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 21:43:47 2010 anthony1 corbacho
// Last update Tue May  4 21:55:26 2010 anthony1 corbacho
//

#include	<iostream>
#include	"SpaceMarine.h"

SpaceMarine::SpaceMarine()
{
  CC = 4;
  CT = 4;
  F = 4;
  E = 4;
  PV = 1;
  I = 4;
  A = 1;
  Cd = 8;
  Svg = 3;
}

SpaceMarine::~SpaceMarine()
{

}

void		SpaceMarine::EnhanceStat(int SpaceMarine::*stat, int increment)
{
  (this->*stat) += increment;
}

void		SpaceMarine::ShowStats()
{
  std::cout << CC << std::endl;
  std::cout << CT << std::endl;
  std::cout << F << std::endl;
  std::cout << E << std::endl;
  std::cout << PV << std::endl;
  std::cout << I << std::endl;
  std::cout << A << std::endl;
  std::cout << Cd << std::endl;
  std::cout << Svg << std::endl;
}
