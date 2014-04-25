/*
** Koala.h for koala in /home/corbac_b/work/piscine/cpp/D03M/ex_0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed May  5 09:55:12 2010 anthony1 corbacho
** Last update Wed May  5 11:11:25 2010 anthony1 corbacho
*/

#ifndef		__KOALA_H__
#define		__KOALA_H__

#include	<iostream>
#include	<string>

class		Koala
{
 public:
  Koala(std::string sex, std::string name);
  Koala(const Koala& k);
  ~Koala();

  Koala& operator=(Koala& val);

  const std::string&	getSex() const;
  const std::string&	getName() const;
  const std::string&	getPicture() const;
  int			getGenIndex() const;

  void			dumpAttributs() const;

 private:
  std::string	_sex;
  std::string	_name;
  std::string	_picture;
  int		_genIndex;

  static int	random(int max);
};

#endif		//__KOALA_H__
