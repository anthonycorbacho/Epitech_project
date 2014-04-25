/*
** AirbusConstructor.h for airbusconstructor in /home/corbac_b/work/piscine/cpp/D01A/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 16:21:00 2010 anthony1 corbacho
** Last update Mon May  3 17:42:55 2010 anthony1 corbacho
*/

#ifndef		__AIRBUSCONSTRUCTOR_H__
#define		__AIRBUSCONSTRUCTOR_H__

#include	"AirbusPlane.h"
#include	"AirbusPieces.h"

class		AirbusConstructor
{
 public:
  AirbusConstructor(char const *PlaneName, int StartingId);
  ~AirbusConstructor();
  Plane		CreatePlane(Pieces *piece);

 private:
  char		*_PlaneName;
  int		_StartingId;
};

#endif		//__AIRBUSCONSTRUCTOR_H__
