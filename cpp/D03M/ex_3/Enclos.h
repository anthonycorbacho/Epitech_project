/*
** Enclos.h for Enclos in /home/corbac_b/work/piscine/cpp/D03M/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed May  5 14:19:58 2010 anthony1 corbacho
** Last update Wed May  5 18:37:04 2010 anthony1 corbacho
*/

#ifndef		__ENCLOS_H__
#define		__ENCLOS_H__

#include	"Koala.h"

class		Enclos
{
 public:
  Enclos();
  Enclos(const Enclos& enclos);
  ~Enclos();
  
  void		operator<<(Koala& koala);
  friend void	operator>>(Koala& koala, Enclos &enclo);
  
  friend std::ostream&   operator<<(std::ostream&, Enclos &enclo);
  void		operator=(Enclos& enclo);
  bool		operator==(Enclos& enclo);
  Koala*	operator[](int indice);
  /* 
  
  */
  // Enclo << Koala
  // *Koala >> Enclo
  //  Enclo = *Enclo
  //  *(Enclo[int]) = Koala
  //  Enclo1 == Enclo2
  // sdt::cout << Enclo1

  int		size(void) const;
  bool		empty(void) const;
  void		push_back(Koala& koalaSrc);
  void		pop_back(void);
  void		insert(int pos, Koala& koalaSrc);
  void		erase(int pos);
  void		clear(void);
  void		dump(void);
  
  

 private:
  Koala**	_tabKoalas;
  int		_nbKoalas;
};

#endif		//__ENCLOS_H__
