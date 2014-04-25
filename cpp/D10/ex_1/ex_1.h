/*
** ex_1.h for ex_1 in /home/Anthony/Epitech/piscine/cpp/piscine/D10/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed May 12 13:35:04 2010 anthony1 corbacho
** Last update Wed May 12 14:33:12 2010 anthony1 corbacho
*/

#ifndef __EX_1_H__
#define __EX_1_H__

template <typename T>
class		Tester
{
 public:
  Tester();
  bool		equal(const T&a, const T&b);
};

template <typename U>
bool		equal(const U&, const U&);

#include "ex_1.cpp"

#endif /*__EX_1_H__*/
