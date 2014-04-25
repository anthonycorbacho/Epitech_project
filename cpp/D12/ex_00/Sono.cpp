//
// Sono.cpp for sono in /home/Anthony/Epitech/piscine/cpp/12h/ex_00
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 20:46:56 2010 anthony1 corbacho
// Last update Thu May 13 21:10:05 2010 anthony1 corbacho
//

#include <iostream>
#include "Sono.h"

Sono::Sono()
{
  volume = 0;
}

Sono::~Sono()
{
}

unsigned int	Sono::getVolume()
{
  return this->volume;
}

void		Sono::setVolume(unsigned int new_volume)
{
  this->volume = new_volume;
}
