/*
** AirbusSupplier.h for Supplier in /home/corbac_b/work/piscine/cpp/D01A/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 17:45:57 2010 anthony1 corbacho
** Last update Mon May  3 18:26:07 2010 anthony1 corbacho
*/

#ifndef		__BOEINGSUPPLIER_H__
#define		__BOEINGSUPPLIER_H__

#include	"BoeingPieces.h"

namespace	Boeing
{
  class		Supplier
  {
  public:
    Supplier();
    ~Supplier();
    Pieces	GetPieces();
  };
}

#endif		//__BOEINGSUPPLIER_H__
