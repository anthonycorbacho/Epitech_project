//
// AirbusPieces.cpp for piece methodes in /home/corbac_b/work/piscine/cpp/D01A/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 17:18:11 2010 anthony1 corbacho
// Last update Mon May  3 18:44:37 2010 anthony1 corbacho
//

#include	"AirbusPieces.h"

namespace       Airbus
{
  Pieces::Pieces(int param)
  {
    _NumPiece = param;
  }

  Pieces::~Pieces()
  {
  }

  int		Pieces::GetNumberOfElement()
  {
    return (this->_NumPiece);
  }

  int		Pieces::SetNumberOfElement(int Id)
  {
    this->_NumPiece = Id;
    return (GetNumberOfElement());
  }
}
