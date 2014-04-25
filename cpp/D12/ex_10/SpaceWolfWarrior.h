#ifndef		__SPACEWOLFWARRIOR_H__
#define		__SPACEWOLFWARRIOR_H__
#include <iostream>
#include "AWarrior.h"
class			SpaceWolfWarrior : public AWarrior
{
 public:

  SpaceWolfWarrior();
  ~SpaceWolfWarrior();

  void			move();
  void			shoot();
  void			charge();
  void			playTurn();

};
#endif		// __SPACEWOLFWARRIOR_H__
