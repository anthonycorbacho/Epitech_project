/*
** Computer.h for computer in /home/Anthony/Epitech/piscine/cpp/24h/ex_15
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 15:47:46 2010 anthony1 corbacho
** Last update Fri May  7 16:38:50 2010 anthony1 corbacho
*/

#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include	<iostream>
#include	<string>

class	Computer
{
 public:
  std::string	getbuffer();

  void			operator<<(std::string);
  friend std::ostream&	operator<<(std::ostream&, Computer c);
 protected:
  std::string	buffer;
};

#endif /*__COMPUTER_H__*/
