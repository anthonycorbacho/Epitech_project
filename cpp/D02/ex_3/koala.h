/*
** koala.h for koala in /home/corbac_b/work/piscine/cpp/D02/ex_3
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May  4 14:53:06 2010 anthony1 corbacho
** Last update Tue May  4 20:49:15 2010 anthony1 corbacho
*/

#ifndef		__KOALA_H__
#define		__KOALA_H__
class		Koala
{
 public:
  Koala();
  ~Koala();
  char		*&Name();
  void		CreateChildren(int children);
  Koala		&GetChild(int child);
  int		GetChildrenCount();
  void		WhoIsYourDaddy();

 private:
  char		*_Name;
  Koala		*_Children;
  int		_NbChild;
  Koala		*_IsDaddy;
};
#endif		//__KOALA_H__
