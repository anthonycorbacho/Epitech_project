/*
** Guard.h for Guard in /home/Anthony/Epitech/piscine/cpp/12h/ex_02
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 12:43:49 2010 anthony1 corbacho
** Last update Fri May 14 13:08:22 2010 anthony1 corbacho
*/

#ifndef __GUARD_H__
#define __GUARD_H__

#include "Room.h"

class		Room;

class		Guard
{
  friend class Room;
 protected:
  bool			_auth;
  public:
  virtual void		inspect(Room const*) const = 0;
  virtual ~Guard () {};
};

#endif /*__GUARD_H__*/
