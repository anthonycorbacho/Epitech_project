/*
** battledroid.h for battledroid in /home/corbac_b/work/piscine/cpp/D04M/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 15:33:34 2010 anthony1 corbacho
** Last update Thu May  6 15:53:10 2010 anthony1 corbacho
*/

#ifndef		__BATTLEDROID_H__
#define		__BATTLEDROID_H__

#include	<iostream>
#include	"droid.h"

class		BattleDroid : virtual public Droid
{
 public:
  BattleDroid();
  ~BattleDroid()
    {
      std::cout << "eeeeeeuuuuuuurrrrrrggggghhh" << std::endl;
    }
  void  Start() const;
  void  Stop() const;
  void	Identification() const;
  void	Fight() const;
};

#endif		//__BATTLEDROID_H__
