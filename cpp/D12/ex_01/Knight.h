/*
** Knight.h for Knight in /home/Anthony/Epitech/piscine/cpp/12h/ex_01
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May 13 21:46:48 2010 anthony1 corbacho
** Last update Fri May 14 12:16:59 2010 anthony1 corbacho
*/

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <iostream>
#include <string>

#include "Stats.h"

class		Knight
{
 private:
  std::string	_armorType;
  std::string	_name;
  int		_cosmos;
  bool		_poweredUp;

 public:
  Knight(std::string const& armor, int cosmos, std::string const& name);
  ~Knight();
  Stats*	powerUp(std::string const&, int);
  void         powerDown(Stats*);
  void		powerDown();
  int		getCosmos() const;
  std::string	getName() const;
  std::string	getArmor() const;

  void		attack(std::string const& name, int cosmosConsumed);
  friend std::ostream&	operator<< (std::ostream&, Knight &);
};
#endif /*__KNIGHT_H__*/
