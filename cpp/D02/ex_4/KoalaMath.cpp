//
// KoalaMath.cpp for Koala_Math in /home/corbac_b/work/piscine/cpp/D02/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 17:01:25 2010 anthony1 corbacho
// Last update Tue May  4 17:26:15 2010 anthony1 corbacho
//

#include	"KoalaMath.h"

namespace	Koala
{
  Koala::KoalaMath::KoalaMath()
  {
    left_operand = 42;
    right_operand = 2;
  }
  
  Koala::KoalaMath::~KoalaMath()
  {
  }

  int	Koala::KoalaMath::
  Add(const int &left_operand, const int &right_operand) const
  {
    return (left_operand + right_operand);
  }

  int   Koala::KoalaMath::
  Div(const int &left_operand, const int &right_operand) const
  {
    if (right_operand != 0)
      return (left_operand / right_operand);
    return (0);
  }

  int   Koala::KoalaMath::
  Sub(const int &left_operand, const int &right_operand) const
  {
    return (left_operand - right_operand);
  }

  int   Koala::KoalaMath::
 Mod(const int &left_operand, const int &right_operand) const
  {
    if (right_operand != 0)
      return (left_operand % right_operand);
    return (0);
  }

  int   Koala::KoalaMath::
  Mul(const int &left_operand, const int &right_operand) const
  {
    return (left_operand * right_operand);
  }

  int        Koala::KoalaMath::
  Calc(int (Koala::KoalaMath::*fct)
       (const int &left_operand, const int &right_operand)const)const
  {
    return ((this->*fct)(this->left_operand , this->right_operand));
  }
}
