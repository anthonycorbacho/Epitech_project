/*
** battledroid.h for battledroid in /home/corbac_b/work/piscine/cpp/D04M/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 14:06:15 2010 anthony1 corbacho
** Last update Thu May  6 14:25:15 2010 anthony1 corbacho
*/

#ifndef		__BATTLEDROID_H__
#define		__BATTLEDROID_H__

#include	"droid.h"

class		battledroid : public Droid
{
 public:
  battledroid();
  ~battledroid();
  void          Identification() const;
  void          Glory() const;
  void          PowerLevel() const;
  bool          LoadPowerCell(int);

  void		Shield();
  void          Blast();

 private:
  int           _unitPower;
};

#endif		//__BATTLEDROID_H__
