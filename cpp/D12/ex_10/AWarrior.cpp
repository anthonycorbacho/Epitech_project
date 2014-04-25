#include "AWarrior.h"

AWarrior::AWarrior()
{
}

AWarrior::~AWarrior()
{
}

void			AWarrior::playTurn()
{
  move();
  shoot();
  charge();
}


