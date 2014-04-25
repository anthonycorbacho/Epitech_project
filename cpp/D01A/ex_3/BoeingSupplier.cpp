//
// AirbusSupplier.cpp for Supplier in /home/corbac_b/work/piscine/cpp/D01A/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 17:57:34 2010 anthony1 corbacho
// Last update Mon May  3 18:54:19 2010 anthony1 corbacho
//

#include "BoeingSupplier.h"
#include "BoeingPieces.h"

namespace       Boeing
{
  Supplier::Supplier()
  {
  }

  Supplier::~Supplier()
  {
  }
  Pieces		Supplier::GetPieces()
  {
    Pieces	piece;
    
    piece.SetNumberOfElement(255);
    return(piece);
  }
}
