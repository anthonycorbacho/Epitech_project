//
// alloc.cpp for alloc in /home/corbac_b/work/piscine/cpp/D04A
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 20:14:10 2010 anthony1 corbacho
// Last update Thu May  6 20:19:22 2010 anthony1 corbacho
//

#include	"alloc.h"
#include	<new>
#include	<iostream>

char*	Alloc::doAlloc(unsigned long i)
{
  return (new (std::nothrow) char[i]);
}
