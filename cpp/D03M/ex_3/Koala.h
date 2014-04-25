/*
** Koala.h for koala in /home/corbac_b/work/piscine/cpp/D03M/ex_0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed May  5 09:55:12 2010 anthony1 corbacho
** Last update Wed May  5 17:59:13 2010 anthony1 corbacho
*/

#ifndef		__KOALA_H__
#define		__KOALA_H__

#include	<iostream>
#include	<string>

class		Koala
{
 public:
  Koala(std::string sex, std::string name);
  Koala(std::string sex, std::string name, std::string picture, int genIndex);
  Koala(const Koala& k);
  ~Koala();

  Koala& operator=(Koala& val);
  Koala* operator+(Koala& mate);
  Koala* operator+(Koala* mate);
  void	 operator<<(std::string ingredient);
  friend Koala&	 operator>>(std::string ingredient, Koala &k);
  friend std::ostream&	 operator<<(std::ostream&, Koala &k);

  const std::string&	getSex() const;
  const std::string&	getName() const;
  const std::string&	getPicture() const;
  int			getGenIndex() const;

  void			dumpAttributs() const;
  void			eat(const std::string ingredient) const;
  Koala			*procreate(const Koala& mate) const;

 private:
  std::string	_sex;
  std::string	_name;
  std::string	_picture;
  int		_genIndex;

  static int	random(int max);
};

#endif		//__KOALA_H__
