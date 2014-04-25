//
// droidmaker.cpp for droidmaker in /home/corbac_b/work/piscine/cpp/D04M/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May  6 13:10:50 2010 anthony1 corbacho
// Last update Thu May  6 14:53:18 2010 anthony1 corbacho
//

#include        "droid.h"
#include	"droidmaker.h"
#include        "R2D2.h"
#include        "C3PO.h"
#include        "battledroid.h"


#include        <iostream>
#include        <string>

Droid	*droidMaker::MakeDroid(std::string DroidType)
{
  Droid	*newdroid;

  if (DroidType == "R2D2")
    {
     newdroid = new r2d2();
    }
  else if (DroidType == "C3PO")
    {
      newdroid = new c3po();
    }
  else
    {
      newdroid = new battledroid();
    }
  return (newdroid);
}
