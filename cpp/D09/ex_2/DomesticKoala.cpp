//
// DomesticKoala.cpp for er in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May 11 19:40:38 2010 anthony1 corbacho
// Last update Tue May 11 21:27:41 2010 anthony1 corbacho
//

#include <iostream>
#include <string>
#include <vector>

#include "KoalaAction.h"
#include "DomesticKoala.h"

typedef void (KoalaAction::*methodPointer_t)(const std::string &);

DomesticKoala::DomesticKoala(KoalaAction& k) : _koala(k)
{
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(const DomesticKoala& dk) : _koala(dk._koala)
{
  int	cpt = dk._do.size();
  for (int i = 0; i < cpt; i++)
    {
      _do.push_back(dk._do[i]);
      _ord.push_back(dk._ord[i]);
    }
}

DomesticKoala&	DomesticKoala::operator=(const DomesticKoala &dk)
{
  if (this != &dk)
    {
      _koala = dk._koala;
      int	cpt = dk._do.size();
      for (int i = 0; i < cpt; i++)
	{
	  _do.push_back(dk._do[i]);
	  _ord.push_back(dk._ord[i]);
	}
    }
  return *this;
}

std::vector<methodPointer_t> const*     DomesticKoala::getActions(void) const
{
  return (&_do);
}

void                DomesticKoala::learnAction(unsigned char order, methodPointer_t func)
{
  if (func != NULL)
    {
      _do.push_back(func);
      _ord.push_back(order);
    }
}

void                DomesticKoala::unlearnAction(unsigned char order)
{
  int		    size = _ord.size();

  for (int i = 0; i < size; i++)
    {
      if (order == _ord[i])
	{
	  _ord.erase(_ord.begin() + i);
	  _do.erase(_do.begin() + i);
	}
    }
}

void                DomesticKoala::doAction(unsigned char order, const std::string& str)
{
  int			size =  _ord.size();
  for (int i = 0; i < size; i++)
    {
      if (order == _ord[i])
	{
	  (_koala.*_do[i])(str);
	  return ;
	}
    }
}

void                DomesticKoala::setKoalaAction(KoalaAction& k)
{
  this->_koala = k;
  this->_do.clear();
}
