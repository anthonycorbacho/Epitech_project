//
// AirbusPlane.cpp for AirbusPlane in /home/corbac_b/work/piscine/cpp/D01A/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 14:38:52 2010 anthony1 corbacho
// Last update Mon May  3 15:44:47 2010 anthony1 corbacho
//

#include	<stdlib.h>
#include	<string.h>
#include	"AirbusPlane.h"

Plane::Plane()
{
  _Id = 0;
  _ConstructorName = "";
  _Flying = 0;
  _isCreated  =0;
}

Plane::~Plane()
{
  free(_ConstructorName);
}

void		Plane::Create(char const* constructor_name, int Id)
{
  if (Id < 0)
    Id = 0;
  this->_Id = Id;
  this->_ConstructorName = strdup(constructor_name);
  this->_isCreated = 1;
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
  return (this->_isCreated);
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
