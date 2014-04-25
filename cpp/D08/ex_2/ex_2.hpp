//
// ex_2.hpp for ex_2 in /home/Anthony/Epitech/piscine/cpp/piscine/D08/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May 10 16:49:27 2010 anthony1 corbacho
// Last update Mon May 10 23:56:07 2010 anthony1 corbacho
//

#ifndef __EX_2_H__
#define __EX_2_H__

#include <iostream>

template<typename T>
T min(T a, T y)
{
  std::cout << "template min" << std::endl;
  if (a < y)
    return (a);
  return (y);
}

int    min(int a, int y)
{
  std::cout << "non-template min" << std::endl;
  if (a < y)
    return (a);
  return (y);
}

template<typename T>
T    templateMin(T tab[], int size)
{
  int    i = 1;
  T	res = tab[0];

  while (i < size)
    {
      res = min<T>(res, tab[i]);
      i += 2;
    }
  return (res);
}

int    nonTemplateMin(int tab[], int size)
{
  int    i = 1;
  int    res;

  res = tab[0];
  while (i < size)
    {
      res = min(res, tab[i]);
      i += 2;
    }
  return (res);
}

#endif /*__EX_2_H__*/
