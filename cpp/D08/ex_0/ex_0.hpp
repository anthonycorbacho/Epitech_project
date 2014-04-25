//
// ex_0.hpp for header ex_0 in /home/Anthony/Epitech/piscine/cpp/piscine/D08/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May 10 13:34:18 2010 anthony1 corbacho
// Last update Mon May 10 14:07:17 2010 anthony1 corbacho
//

#ifndef __EX_0_H__
#define __EX_0_H__

template<typename T>
void	swap(T &A, T &B)
{
  T tmp = A;
  A = B;
  B = tmp;
}

template<typename R>
R min(R &a, R &b)
{
  if (a < b)
    return a;
  return b;
}

template<typename R>
R max(R &a, R &b)
{
  if (a < b)
    return b;
  return a;
}

template<typename R>
R add(R &a, R &b)
{
  return (a + b);
}

#endif /*__EX_0_H__*/
