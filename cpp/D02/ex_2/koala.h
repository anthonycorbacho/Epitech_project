/*
** koala.h for koala class in /home/corbac_b/work/piscine/cpp/D02/ex_2
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May  4 10:48:28 2010 anthony1 corbacho
** Last update Tue May  4 12:48:38 2010 anthony1 corbacho
*/

#ifndef		__KOALE_H__
#define		__KOALA_H__
class		Koala
{
 public:
  Koala(const char *name);
  Koala(const char *name, Koala *koala);
  ~Koala();
  void		AddPartner(const char *name);
  Koala		&GetPartner();
  void		SetPartner(Koala *koala);
  void		KillPartner();
  const char	*GetName();
  void		DANCE();

 private:
  const char	*_Name;
  Koala		*_Partner;
};
#endif		//__KOALA_H__
