//
// Sujets.cpp for Suject in /home/Anthony/Epitech/piscine/cpp/12h/ex_04
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May 14 13:52:19 2010 anthony1 corbacho
// Last update Fri May 14 14:00:22 2010 anthony1 corbacho
//

#include <iostream>
#include "Sujets.h"


SujetRelou::SujetRelou()
{
  _name = "Relou";
  std::cout << "Nouveau Sujet : Relou" << std::endl;
}

SujetRelou::~SujetRelou()
{
  std::cout << "Delete Sujet : Relou" << std::endl;
}

AbsSujet *SujetRelou::copy()
{
  AbsSujet	*s;
  s = new  SujetRelou();
  return (s);
}

SujetNoob::SujetNoob()
{
  _name = "Noob";
  std::cout << "Nouveau Sujet : Noob" << std::endl;
}

SujetNoob::~SujetNoob()
{
  std::cout << "Delete Sujet : Noob" << std::endl;
}

AbsSujet *SujetNoob::copy()
{
  AbsSujet	*s;
  s = new  SujetNoob();
  return (s);
}

SujetRoxor::SujetRoxor()
{
  _name = "Roxor";
  std::cout << "Nouveau Sujet : Roxor" << std::endl;
}

SujetRoxor::~SujetRoxor()
{
  std::cout << "Delete Sujet : Roxor" << std::endl;
}

AbsSujet *SujetRoxor::copy()
{
  AbsSujet	*s;
  s = new  SujetRoxor();
  return (s);
}

SujetUltime::SujetUltime()
{
  std::cout << "Nouveau Sujet : Ultime" << std::endl;
}

SujetUltime::~SujetUltime()
{
  std::cout << "Delete Sujet : Ultime" << std::endl;
}

AbsSujet *SujetUltime::copy()
{
  AbsSujet	*s;
  s = new  SujetUltime();
  return (s);
}
