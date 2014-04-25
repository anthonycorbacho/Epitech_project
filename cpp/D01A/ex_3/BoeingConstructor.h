/*
** AirbusConstructor.h for airbusconstructor in /home/corbac_b/work/piscine/cpp/D01A/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 16:21:00 2010 anthony1 corbacho
** Last update Mon May  3 18:49:08 2010 anthony1 corbacho
*/

#ifndef		__BOEINGCONSTRUCTOR_H__
#define		__BOEINGCONSTRUCTOR_H__

#include	"BoeingPlane.h"
#include	"BoeingPieces.h"

class		BoeingConstructor
{
 public:
  BoeingConstructor(char const *PlaneName, int StartingId);
  ~BoeingConstructor();
  Boeing::Plane		CreatePlane(Boeing::Pieces *piece);
  
 private:
  char		*_PlaneName;
  int		_StartingId;
};

#endif		//__BOEINGCONSTRUCTOR_H__
