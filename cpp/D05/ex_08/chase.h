/*
** chase.h for chase in /home/Anthony/Epitech/piscine/cpp/24h
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May  7 13:29:46 2010 anthony1 corbacho
** Last update Fri May  7 13:31:21 2010 anthony1 corbacho
*/

#ifndef __CHASE_H__
#define __CHASE_H__

struct chase
{
chase() : spotted(false), walk(0) {}
  bool spotted;
  long walk;
};
#endif /*__CHASE_H__*/
