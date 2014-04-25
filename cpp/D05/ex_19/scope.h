/*
** scope.h for scope in /home/Anthony/Epitech/piscine/cpp/24h/ex_19
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 19:15:28 2010 anthony1 corbacho
** Last update Fri May  7 19:16:00 2010 anthony1 corbacho
*/

#ifndef __SCOPE_H__
#define __SCOPE_H__

#include <iostream>
using namespace std;

namespace A
{
  typedef shortFixnum;
  
  Fixnum f;
  namespace B
  {
    typedef intBignum;
    
    Bignum f;
    Bignum g; 
    
    namespace C
    {
      typedef doubleFloat;
      
      Float f;
      Float g;
      Float h;
    };
  };
  B::C::Floati;
};
using namespace A;
using A::B::g;
namespace X = A;
namespace Y = A::B::C;

#endif /*__SCOPE_H__*/
