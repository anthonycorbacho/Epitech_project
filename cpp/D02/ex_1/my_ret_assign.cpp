//
// my_ret_assign.cpp for my_ret_assign in /home/corbac_b/work/piscine/cpp/D02/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 10:32:28 2010 anthony1 corbacho
// Last update Tue May  4 12:10:59 2010 anthony1 corbacho
//

#include	"my_ret_assign.h"

int		&my_ret_assign(struct Koala &k)
{
  return (k.age);
}
