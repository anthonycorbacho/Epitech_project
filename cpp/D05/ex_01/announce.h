/*
** annouce.h for annouce in /home/Anthony/Epitech/piscine/cpp/24h/ex_01
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 01:59:13 2010 anthony1 corbacho
** Last update Fri May  7 13:19:56 2010 anthony1 corbacho
*/

#ifndef __ANNOUCE_H_H__
#define __ANNOUCE_H_H__

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include	"reminder.h"

class		announce : public reminder
{
 public:
  announce();
  ~announce();
  int	voiceover(int val);
};

#endif /*__ANNOUCE_H_H__*/
