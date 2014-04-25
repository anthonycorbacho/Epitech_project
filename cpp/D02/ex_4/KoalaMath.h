/*
** KoalaMath.h for KoalaMath in /home/corbac_b/work/piscine/cpp/D02/ex_4
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May  4 16:47:54 2010 anthony1 corbacho
** Last update Tue May  4 17:00:58 2010 anthony1 corbacho
*/

#ifndef		__KOALA_MATH_H__
#define		__KOALA_MATH_H__

namespace	Koala
{
  class		KoalaMath
  {
  public:
    int		left_operand;
    int		right_operand;

    KoalaMath();
    ~KoalaMath();

    int		Add(const int &left_operand, const int &right_operand) const;
    int		Div(const int &left_operand, const int &right_operand) const;
    int		Sub(const int &left_operand, const int &right_operand) const;
    int		Mod(const int &left_operand, const int &right_operand) const;
    int		Mul(const int &left_operand, const int &right_operand) const;

    int		Calc(int (Koala::KoalaMath::*fct)
		     (const int &left_operand, const int &right_operand)
		     const)const;
  };
}

#endif		//__KOALA_MATH_H__
