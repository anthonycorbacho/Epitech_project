//
// ex_01.hpp for ex_1 in /home/Anthony/Epitech/piscine/cpp/piscine/D08/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May 10 15:15:35 2010 anthony1 corbacho
// Last update Mon May 10 19:15:19 2010 anthony1 corbacho
//

#ifndef __EX_1_H__
#define __EX_1_H__

#include <typeinfo>
#include <stdio.h>
#include <string.h>

template<typename T>
int compare(const T &a, const T &b)
{
  if (typeid(T) == typeid(const char *))
    {
      int	m = 0;
      m = strcmp(*(const char **)(&a), *(const char **)(&b));
      if (m < 0)
	return -1;
      if (m == 0) 
	return 0;
      if (m > 0)
	return 1;
    }
  if (a == b)
    return 0;
  if (a < b)
    return -1;
  return 1;
}

#endif /*__EX_1_H__*/
