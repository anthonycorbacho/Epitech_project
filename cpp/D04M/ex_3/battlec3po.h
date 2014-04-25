/*
** battlec3po.h for ba in /home/corbac_b/work/piscine/cpp/D04M/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 15:51:10 2010 anthony1 corbacho
** Last update Thu May  6 15:52:31 2010 anthony1 corbacho
*/
#ifndef __BATTLEC3PO_H__
#define __BATTLEC3PO_H__

#include <iostream>
#include "droid.h"
#include "c3po.h"
#include "battledroid.h"

class		BattleC3PO : public BattleDroid, public C3PO
{
 public:
  BattleC3PO();
  ~BattleC3PO()
    {
      std::cout << "BattleC3PO Termination" << std::endl;
    }
  void		Start() const;
  void		Stop() const;
  void		Identification() const;
  void		Speak() const;
  void		Fight() const;
};

#endif /*  __BATTLEC3PO_H__ */
