/*
** organisation.h for organisation in /home/Anthony/Epitech/piscine/cpp/24h/ex_18
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 17:36:30 2010 anthony1 corbacho
** Last update Fri May  7 17:37:01 2010 anthony1 corbacho
*/


#ifndef __ORGANISATION_H__
#define __ORGANISATION_H__

#include "terrorist.h"

class Organisation
{
 private:
  int		_membersNumber;
  Terrorist	membersTable[];
 public:
  Organisation();
  void		addMember(Terrorist);
  int		getMemberNumber();
};

#endif /*__ORGANISATION_H__*/



