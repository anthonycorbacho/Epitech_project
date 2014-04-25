/*
** SpaceMarine.h for SpcaeMarine in /home/corbac_b/work/piscine/cpp/D02/ex_6
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May  4 21:33:42 2010 anthony1 corbacho
** Last update Tue May  4 21:46:57 2010 anthony1 corbacho
*/

#ifndef		__SPACEMARINE_H__
#define		__SPACEMARINE_H__

class		SpaceMarine
{
 public:
  int		CC;
  int		CT;
  int		F;
  int		E;
  int		PV;
  int		I;
  int		A;
  int		Cd;
  int		Svg;

  SpaceMarine();
  ~SpaceMarine();
  void		EnhanceStat(int SpaceMarine::*stat, int increment);
  void		ShowStats();

};

#endif		//__SPACEMARINE_H__
