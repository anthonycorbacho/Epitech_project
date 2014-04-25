/*
** Sujets.h for Sujet in /home/Anthony/Epitech/piscine/cpp/12h/ex_04
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri May 14 13:53:35 2010 anthony1 corbacho
** Last update Fri May 14 13:54:18 2010 anthony1 corbacho
*/

#ifndef __H_SUJETS__
#define __H_SUJETS__

#include "AbsSujet.h"

class SujetRelou : public AbsSujet
{
 public:
  SujetRelou();
  ~SujetRelou();
  AbsSujet *copy();
};

class SujetNoob : public AbsSujet
{
 public:
  SujetNoob();
  ~SujetNoob();
  AbsSujet *copy();
};

class SujetRoxor : public AbsSujet
{
 public:
  SujetRoxor();
  ~SujetRoxor();
  AbsSujet *copy();
};

class SujetUltime : public AbsSujet
{
 public:
  SujetUltime();
  ~SujetUltime();
  AbsSujet *copy();
};

#endif	//_H_SUJET_
