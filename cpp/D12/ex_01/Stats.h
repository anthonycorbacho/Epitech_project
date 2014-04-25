/*
** Stats.h for Stats in /home/Anthony/Epitech/piscine/cpp/12h/ex_01
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 11:40:57 2010 anthony1 corbacho
** Last update Fri May 14 12:18:35 2010 anthony1 corbacho
*/

#ifndef __STATS_H__
#define __STATS_H__

#include <iostream>
#include <string>

class		Stats
{
 public:
  Stats(std::string const&, int);
  ~Stats();

 private:
  friend class	Knight;
  std::string	armor;
  int		cosmos;
};

#endif /*__STATS_H__*/
