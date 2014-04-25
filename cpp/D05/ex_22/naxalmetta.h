/*
** naxalmetta.h for naxalmetta.h in /home/Anthony/Epitech/piscine/cpp/24h/ex_22
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 18:11:41 2010 anthony1 corbacho
** Last update Fri May  7 17:25:15 2010 anthony1 corbacho
*/
#ifndef __NAXALMETTA_H__
#define __NAXALMETTA_H__

class naxalmetta
{
 public:
  inline bool     kickass() 
  { 
    cout << "you've been naxed" << endl;
    return (1);
  }
  
  inline bool takeoutthegun(int arsenal) 
  {
    arsenal--;
    if (arsenal != 0)
      takeoutthegun(arsenal);
    return (0);
  }
  
  inline bool beatthemall() 
  {
    for (int i = 0; i < 32; ++i)
      {
	this->kickass();
      }
    return (0);
  }
};
#endif /*__NAXALMETTA_H__*/
