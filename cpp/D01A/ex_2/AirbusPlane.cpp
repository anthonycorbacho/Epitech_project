//
// AirbusPlane.cpp for AirbusPlane in /home/corbac_b/work/piscine/cpp/D01A/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 14:38:52 2010 anthony1 corbacho
// Last update Mon May  3 17:39:12 2010 anthony1 corbacho
//

#include	<stdlib.h>
#include	<string.h>
#include	"AirbusPlane.h"

Plane::Plane(char const * constructor_name, int Id, Pieces *piece)
{
  if (Id < 0)
    Id = 0;
  _Id = Id;
  _ConstructorName = strdup(constructor_name);
  _Flying = 0;
  _isCreated  = 1;
  piece->SetNumberOfElement(0);
}

Plane::~Plane()
{
  free(_ConstructorName);
}

void		Plane::Fly()
{
  this->_Flying = 1;
}

void		Plane::Land()
{
  this->_Flying = 0;
}

bool		Plane::IsCreated()
{
  if (this->_isCreated == 1)
    return (1);
  else
    return (0);
}

bool		Plane::IsFlying()
{
  if (this->_Flying == 1)
    return (1);
  else
    return (0);
}

int		Plane::GetId()
{
  return (this->_Id);
}

const	char*	Plane::GetConstructorName()
{
  return (this->_ConstructorName);
}
