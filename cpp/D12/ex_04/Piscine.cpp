//
// Piscine.cpp for Piscine in /home/Anthony/Epitech/piscine/cpp/12h/ex_04
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 13:50:37 2010 anthony1 corbacho
// Last update Fri May 14 16:55:32 2010 anthony1 corbacho
//

#include "Piscine.h"
#include <iostream>

Piscine::Piscine()
{
  std::cout << "Nouvelle piscine" << std::endl;
}

Piscine::Piscine(Piscine &p)
{
  int		i = 0;
  //AbsSujet	*s;

  while (i < (int) p.v.size())
    {
      push(p.v[i]->copy());
      i++;
    }
}

Piscine::~Piscine()
{
  int		i = 0;

  std::cout
    << "Fin d une vielle piscine"
    << std::endl;
  
  while (i < (int) this->v.size())
    {
      delete (this->v[i]);
      i++;
    }
}

void			Piscine::push(AbsSujet *s)
{
  v.push_back(s);
}

void			Piscine::print(void) const
{
  int			i = 0;
  
  std::cout << "Liste exos piscine :";
  while (i < (int) v.size())
    {
      std::cout << " " << v[i]->getName();
      i++;
    }
  std::cout << std::endl;
}
