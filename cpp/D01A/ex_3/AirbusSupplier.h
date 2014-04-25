/*
** AirbusSupplier.h for Supplier in /home/corbac_b/work/piscine/cpp/D01A/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 17:45:57 2010 anthony1 corbacho
** Last update Mon May  3 18:41:07 2010 anthony1 corbacho
*/

#ifndef		__AIRBUSSUPPLIER_H__
#define		__AIRBUSSUPPLIER_H__

#include	"AirbusPieces.h"

namespace	Airbus
{
  class		Supplier
  {
  public:
    Supplier();
    ~Supplier();
    Pieces	GetPieces();
  };
}

#endif		//__AIRBUSSUPPLIER_H__
