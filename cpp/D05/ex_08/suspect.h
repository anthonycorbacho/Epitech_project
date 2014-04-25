/*
** suspect.h for suspect in /home/Anthony/Epitech/piscine/cpp/24h
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 13:27:03 2010 anthony1 corbacho
** Last update Fri May  7 13:29:24 2010 anthony1 corbacho
*/

#ifndef __SUSPECT_H__
#define __SUSPECT_H__
struct suspect                                                                                                                                                                                               
{
suspect() : stopped(true), walk(0), arrived(false) {}                                                                                                                      
  bool stopped;
  int walk;
  bool arrived;
};
#endif /*__SUSPECT_H__*/
