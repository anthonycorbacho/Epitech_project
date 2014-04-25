/*
** AirbusPieces.h for AirbusPiece in /home/corbac_b/work/piscine/cpp/D01A/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon May  3 17:12:05 2010 anthony1 corbacho
** Last update Mon May  3 17:36:56 2010 anthony1 corbacho
*/

#ifndef		__AIRBUSPIECES_H__
#define		__AIRBUSPIECES_H__

class		Pieces
{
 public:
  Pieces(int param = 0);
  ~Pieces();
  int		GetNumberOfElement();
  int		SetNumberOfElement(int Id);

 private:
  int		_NumPiece;
};

#endif		//__AIRBUSPIECES_H__
