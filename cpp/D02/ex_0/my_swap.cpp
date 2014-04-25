//
// my_swap.cpp for my_swap_main in /home/corbac_b/work/piscine/cpp/D02/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 10:20:32 2010 anthony1 corbacho
// Last update Tue May  4 10:22:46 2010 anthony1 corbacho
//

#include	"my_swap.h"
#include	<iostream>

void		my_swap(int &a, int &b)
{
  int		save;

  save = a;
  a = b;
  b = save;
}
