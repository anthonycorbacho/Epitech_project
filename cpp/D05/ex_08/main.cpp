//
// main.cpp for main in /home/Anthony/Epitech/piscine/cpp/24h/ex_08
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 19:10:39 2010 anthony1 corbacho
// Last update Fri May  7 19:12:15 2010 anthony1 corbacho
//

#include "chase.h"
#include "suspect.h"

int main()
{
  suspect marouane;
  chase filth;

  while (!marouane.arrived())
    {
      if (filth.spotted)
        {
	  continue;
        }
      if (marouane.stopped)
        {
	  break;
        }
      filth.walk++;
      marouane.walk++;
    }
}
