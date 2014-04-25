/*
** AirbusConstructor.c for airbusConstructor in /home/corbac_b/work/piscine/cpp/D01A/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 16:28:22 2010 anthony1 corbacho
// Last update Mon May  3 18:57:49 2010 anthony1 corbacho
*/

#include        <stdlib.h>
#include        <string.h>
#include        "BoeingPlane.h"
#include	"BoeingConstructor.h"
#include	"BoeingPieces.h"

BoeingConstructor::BoeingConstructor(char const *PlaneName, int StartingId)
{
  _PlaneName = strdup(PlaneName);
  _StartingId = StartingId;
}

BoeingConstructor::~BoeingConstructor()
{
  free(_PlaneName);
}

Boeing::Plane		BoeingConstructor::CreatePlane(Boeing::Pieces *piece)
{
  Boeing::Plane		plane(this->_PlaneName, this->_StartingId, piece);

  this->_StartingId += 1;
  return (plane);
}
