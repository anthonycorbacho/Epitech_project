//
// ex_3.hpp for ex_3 in /home/Anthony/Epitech/piscine/cpp/piscine/D08/ex_3
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May 10 17:23:46 2010 anthony1 corbacho
// Last update Mon May 10 17:42:53 2010 anthony1 corbacho
//

#ifndef __EX_3_H__
#define __EX_3_H__

#include <iostream>

template<typename T>
void   print(const T &begin)
{
  std::cout << begin << std::endl;
}

template<typename T>
void	foreach(T *begin, void (&func)(const T& elem), int taille)
{
  for (int i = 0; i < taille; i++)
    func(begin[i]);
}

#endif /*__EX_3_H__*/
