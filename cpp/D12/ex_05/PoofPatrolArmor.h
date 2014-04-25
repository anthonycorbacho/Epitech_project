/*
** PoofPatrolArmor.h for poofpatrolarmor in /media/Vash/D12/ex_05
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 17:00:49 2010 anthony1 corbacho
** Last update Fri May 14 17:01:06 2010 anthony1 corbacho
*/

#ifndef		__POOFPATROLARMOR_H__
#define		__POOFPATROLARMOR_H__

#include <iostream>
#include <string>

class		PoofPatrolArmor
{
 public:
  PoofPatrolArmor(std::string const &desc);
  ~PoofPatrolArmor();
  void			assemble(PoofPatrolArmor *armor);
  std::string		describe() const;
 
 private:
  std::string		description;
  PoofPatrolArmor	*other;
};

#endif		// __POOFPATROLARMOR_H__
