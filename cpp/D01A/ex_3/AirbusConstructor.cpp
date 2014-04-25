/*
** AirbusConstructor.c for airbusConstructor in /home/corbac_b/work/piscine/cpp/D01A/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 16:28:22 2010 anthony1 corbacho
// Last update Mon May  3 18:57:19 2010 anthony1 corbacho
*/

#include        <stdlib.h>
#include        <string.h>
#include        "AirbusPlane.h"
#include	"AirbusConstructor.h"
#include	"AirbusPieces.h"

AirbusConstructor::AirbusConstructor(char const *PlaneName, int StartingId)
{
  _PlaneName = strdup(PlaneName);
  _StartingId = StartingId;
}
  
AirbusConstructor::~AirbusConstructor()
{
  free(_PlaneName);
}
  
Airbus::Plane		AirbusConstructor::CreatePlane(Airbus::Pieces *piece)
{
  Airbus::Plane		plane(this->_PlaneName, this->_StartingId, piece);
  
  this->_StartingId += 1;
  return (plane);
}
