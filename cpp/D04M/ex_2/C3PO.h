/*
** C3PO.h for c3po in /home/corbac_b/work/piscine/cpp/D04M/ex_1
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 11:40:47 2010 anthony1 corbacho
** Last update Thu May  6 14:47:05 2010 anthony1 corbacho
*/


#ifndef		__C_H__
#define		__C_H__
#include	"droid.h"

class		c3po : public Droid
{
 public:
  c3po();
  ~c3po();
  void		Identification() const;
  void		Glory() const;
  void          PowerLevel() const;
  bool          LoadPowerCell(int);

  void		Speak();
  void		Escape();

 private:
  int		_unitPower;
};

#endif		//__C_H__
