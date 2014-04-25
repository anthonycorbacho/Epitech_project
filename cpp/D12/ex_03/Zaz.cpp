//
// Zaz.cpp for Zaz in /home/Anthony/Epitech/piscine/cpp/12h/ex_03
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 15:16:19 2010 anthony1 corbacho
// Last update Fri May 14 15:17:31 2010 anthony1 corbacho
//

#include "Zaz.h"

Zaz *Zaz::_Zaz = NULL;

Zaz::Zaz()
{
}

Zaz::~Zaz()
{
}

Zaz*		Zaz::getInstance()
{
  if (_Zaz == NULL)
    {
      std::cout
	<< "Je cree un zaz ... OMFG" 
	<< std::endl;
      _Zaz = new Zaz();
    }
  return (_Zaz);
}

void		Zaz::deleteInstance()
{
  if (_Zaz != NULL)
    {
      std::cout
	<< "je supprime le zaz, :D:D:D:D"
	<< std::endl;
      delete(_Zaz);
      _Zaz = NULL;
    }
}

void		Zaz::porterUnToast()
{
  std::cout
    << "Je voudrais porter un toast"
    << std::endl;
}
