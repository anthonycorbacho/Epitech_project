//
// MagicVolume.cpp for MagicVolume in /home/Anthony/Epitech/piscine/cpp/12h/ex_00
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 20:49:04 2010 anthony1 corbacho
// Last update Thu May 13 21:17:52 2010 anthony1 corbacho
//

#include "Sono.h"
#include "MagicVolume.h"

MagicVolume::MagicVolume(Sono &sono, unsigned int volume)
{
  mySono = &sono;
  required_volume = sono.getVolume();
  sono.setVolume(volume);
}

MagicVolume::~MagicVolume()
{
  mySono->setVolume(this->required_volume);
}
