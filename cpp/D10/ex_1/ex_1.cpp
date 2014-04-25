//
// ex_1.cpp for ex_1 in /home/Anthony/Epitech/piscine/cpp/piscine/D10/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May 12 13:35:25 2010 anthony1 corbacho
// Last update Wed May 12 14:33:51 2010 anthony1 corbacho
//

#ifndef __EX_1_H_C__
#define __EX_1_H_C__
#include "ex_1.h"


template <typename T>
Tester<T>::Tester()
{
}

template <typename T>
bool	Tester<T>::equal(const T& a, const T& b)
{
    return a == b;
}

template <typename U>
bool		equal(const U& a, const U& b)
{
  return a == b;
}

#endif /*__EX_1_H_C__*/
