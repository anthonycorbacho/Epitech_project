//
// AirbusSupplier.cpp for Supplier in /home/corbac_b/work/piscine/cpp/D01A/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 17:57:34 2010 anthony1 corbacho
// Last update Mon May  3 18:03:15 2010 anthony1 corbacho
//

#include "AirbusSupplier.h"
#include "AirbusPieces.h"

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
