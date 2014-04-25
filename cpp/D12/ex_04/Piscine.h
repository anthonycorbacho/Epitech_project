/*
** Piscine.h for Piscine in /home/Anthony/Epitech/piscine/cpp/12h/ex_04
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 13:51:22 2010 anthony1 corbacho
** Last update Fri May 14 13:52:05 2010 anthony1 corbacho
*/

#ifndef __H_PISCINE__
#define __H_PISCINE__

#include "AbsSujet.h"
#include <iostream>
#include <vector>

class Piscine{
 public:
  Piscine();
  ~Piscine();
  Piscine(Piscine &);
  void push(AbsSujet*);
  void print(void) const;

 private:
  std::vector<AbsSujet *> v;
  
};

#endif //__H_PISCINE__
