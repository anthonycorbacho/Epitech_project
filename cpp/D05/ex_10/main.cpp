//
// main.cpp for main in /home/Anthony/Epitech/piscine/cpp/24h
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 16:47:42 2010 anthony1 corbacho
// Last update Fri May  7 16:53:07 2010 anthony1 corbacho
//
#include	<iostream>
#include "analyst.h"

int main()
{
  void* place = static_cast<void*>(new char[sizeof(analyst)]);
  analyst *newbie = 0;
  
  newbie = new (place)analyst();
  newbie->workAlot();
  delete newbie;
}
