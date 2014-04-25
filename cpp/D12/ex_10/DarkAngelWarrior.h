#ifndef		__DARKANGELWARRIOR_H__
#define		__DARKANGELWARRIOR_H__

#include <iostream>
#include "AWarrior.h"

class			DarkAngelWarrior : public AWarrior
{
 public:
  DarkAngelWarrior();
  ~DarkAngelWarrior();

  void			move();
  void			shoot();
  void			charge();
  void			playTurn();
};
#endif		// __DARKANGELWARRIOR_H__
