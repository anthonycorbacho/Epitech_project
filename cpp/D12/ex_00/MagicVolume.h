/*
** MagicVolume.h for MagicVolume in /home/Anthony/Epitech/piscine/cpp/12h/ex_00
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 20:48:29 2010 anthony1 corbacho
** Last update Thu May 13 21:16:30 2010 anthony1 corbacho
*/

#ifndef __MAGICVOLUME_H__
#define __MAGICVOLUME_H__

#include "Sono.h"

class		Sono;

class		MagicVolume
{
 public:
  MagicVolume(Sono &Sono, unsigned int volume);
  ~MagicVolume();

 private:
  Sono		*mySono;
  unsigned int	required_volume;
};

#endif /*__MAGICVOLUME_H__*/
