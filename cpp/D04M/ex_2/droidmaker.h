/*
** droidmaker.h for droidmaker in /home/corbac_b/work/piscine/cpp/D04M/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu May  6 13:05:57 2010 anthony1 corbacho
** Last update Thu May  6 14:42:13 2010 anthony1 corbacho
*/

#ifndef		__DROIDMAKER_H__
#define		__DROIDMAKER_H__

#include	"droid.h"
#include	"R2D2.h"
#include	"C3PO.h"
#include	"battledroid.h"

#include	<iostream>
#include	<string>

class		droidMaker
{
 public:
  static Droid	*MakeDroid(std::string DroidType);
};
#endif		//__DROIDMAKER_H__
