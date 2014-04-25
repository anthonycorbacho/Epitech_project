//
// Enclos.cpp for enclos in /home/corbac_b/work/piscine/cpp/D03M/ex_3
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May  5 14:29:40 2010 anthony1 corbacho
// Last update Wed May  5 22:13:07 2010 anthony1 corbacho
//

#include	<iostream>
#include	"Koala.h"
#include	"Enclos.h"

Enclos::Enclos()
{
  _tabKoalas = 0;
  _nbKoalas = 0;
}

Enclos::Enclos(const Enclos& enclos)
{
  _tabKoalas = enclos._tabKoalas;
  _nbKoalas = enclos._nbKoalas;
}

Enclos::~Enclos()
{
}

void		Enclos::push_back(Koala& koalaSrc)
{
  Koala		**save = new Koala *[_nbKoalas]();
  int		i;

  i = 0;
  while (i < this->_nbKoalas)
    {
      save[i] = this->_tabKoalas[i];
      i++;
    }
  this->_tabKoalas = new Koala *[_nbKoalas + 1]();
  i = 0;
  while (i < this->_nbKoalas)
    {
      this->_tabKoalas[i] = save[i];
      i++;
    }
  this->_nbKoalas += 1;
  this->_tabKoalas[i] = &koalaSrc;
  std::cout <<"["<<koalaSrc.getName() <<"] s'est fait 'Encloter' !" << std::endl;
}

void		Enclos::dump(void)
{
  for(int i = 0; i < this->_nbKoalas; i++)
    {
      std::cout
	<<
	this->_tabKoalas[i]->getName()
	<< std::endl;
    }
}

void		Enclos::erase(int pos)
{
  std::cout << "Supression du Koala 'Enclote' : [" <<
    this->_tabKoalas[pos]->getName() << "]" << std::endl;
  for (int i = pos; i < (this->_nbKoalas - 1); i++)
    {
      this->_tabKoalas[i] = this->_tabKoalas[i + 1];
    }
  this->_nbKoalas -= 1;
}

int		Enclos::size(void) const
{
  return (this->_nbKoalas);
}

bool		Enclos::empty(void) const
{
  if (this->_nbKoalas > 0)
    return (0);
  else
    return (1);
}

void		Enclos::pop_back(void)
{
  if (this->_nbKoalas == 0)
    std::cout 
      <<
      "Il n'y a aucun Koala dans l'enclos"
      << std::endl;
  else
    {
      std::cout
	<< "[" <<
	this->_tabKoalas[_nbKoalas -1]->getName()
	<< "] s'est fait 'Desencloter'!"
	<< std::endl;
      this->_tabKoalas[_nbKoalas -1] = 0;
      this->_nbKoalas -= 1;
    }
}

void		Enclos::insert(int pos, Koala& koalaSrc)
{
  if (pos > this->size())
    {
      std::cout 
      <<
	"Impossible d'inserer le Koala["
      <<
	koalaSrc.getName()
      <<
	"] !"
      << std::endl;
    }
  if (pos < 0)
    return ;
  if (this->_tabKoalas[pos] != 0)
    {
       std::cout 
      <<
	 "["
      <<
	 this->_tabKoalas[pos]->getName()
      <<
	"] s'est fait remplacer par ["
      <<
	koalaSrc.getName()
      <<
	"] !"
      << std::endl;
    }
  this->_tabKoalas[pos] = &koalaSrc;
}

void		Enclos::clear()
{
  this->_tabKoalas = 0;
  this->_nbKoalas = 0;
}

void		Enclos::operator<<(Koala& k)
{
  this->push_back(k);
}

void		operator>>(Koala& k, Enclos& enclo)
{
  enclo.push_back(k);
}

std::ostream&	operator<<(std::ostream& o, Enclos& enclo)
{
  o
    <<
    "Nombre de Koala dans l'enclos : "
    <<
    enclo.size()
    << std::endl;

  o
    <<
    "List des Koalas de l'enclos :"
    << std::endl;
    
  for(int i = 0; i < enclo._nbKoalas; i++)
    {
      o
	<<
	enclo._tabKoalas[i]->getName()
	<< std::endl;
    }
  return (o);
}

void		Enclos::operator=(Enclos& enclo)
{
  for (int i = 0; i < enclo._nbKoalas; i++)
    {
      this->push_back(*enclo._tabKoalas[i]);
    }
}

bool          Enclos::operator==(Enclos& enclo)
{
  if (this != &enclo)
    return (0);
  else
    {
      if (this->_nbKoalas != enclo._nbKoalas)
	return (0);
      for (int i = 0; i < this->_nbKoalas; i++)
	{
	  if (this->_tabKoalas[i] != enclo._tabKoalas[i])
	    return (0);
	}
      return (1);
    }
}

Koala*		Enclos::operator[](int indice)
{
  return (this->_tabKoalas[indice]);
}
