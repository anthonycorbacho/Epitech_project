/*
** Alcohol.h for Alchol in /home/corbac_b/work/piscine/cpp/D02/ex_5
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May  4 18:42:18 2010 anthony1 corbacho
** Last update Tue May  4 23:39:32 2010 anthony1 corbacho
*/

#ifndef		__ALCOHOL_H__
#define		__ALCOHOL_H__

class		Alcohol
{
 public:
  Alcohol();
  ~Alcohol();
  int		&getAvailebleAlcohol();

 private: 
  static int	_Unit;
};

#endif		//__ALCOHOL_H__
