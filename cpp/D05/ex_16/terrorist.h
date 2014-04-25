/*
** terrorist.h for terro in /home/Anthony/Epitech/piscine/cpp/24h/ex_16
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 16:43:51 2010 anthony1 corbacho
** Last update Fri May  7 16:52:01 2010 anthony1 corbacho
*/

#ifndef __TERRORIST_H__
#define __TERRORIST_H__

#include	<iostream>
#include	<string>

class		Terrorist
{
 public:
  void		setGun(std::string String);
  void		setName(std::string String);
  std::string	getGun();
  std::string	getName();
 private:
  std::string	_name;
  std::string	_gun;
};

#endif /*__TERRORIST_H__*/
