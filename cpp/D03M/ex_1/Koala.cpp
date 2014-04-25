//
// Koala.cpp for koala in /home/corbac_b/work/piscine/cpp/D03M/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Wed May  5 10:04:56 2010 anthony1 corbacho
// Last update Wed May  5 17:51:59 2010 anthony1 corbacho
//

#include	<iostream>
#include	<stdlib.h>
#include	<string>

#include	"Koalascii.h"
#include	"Koala.h"

Koala::Koala(std::string sex, std::string name)
{
  int	genered;
  
  genered = random(5);
  _sex = sex;
  _name = name;
  if (sex == "male")
    _picture = KoalaScii[0][genered];
  else
    _picture = KoalaScii[genered][0];
  _genIndex = genered;
}

Koala::Koala(std::string sex, std::string name, std::string picture, int genIndex)
{
  _sex = sex;
  _name = name;
  _picture = picture;
  _genIndex = genIndex;
}

Koala::Koala(const Koala& k)
{
  _sex = k._sex;
  _name = k._name;
  _picture = k._picture;
  _genIndex = k._genIndex;
}

Koala::~Koala()
{

}

Koala&		Koala::operator=(Koala& val)
{
  if (this != &val)
    {
      this->_sex = val._sex;
      this->_name = val._name;
      this->_picture = val._picture;
      this->_genIndex = val._genIndex;
    }
  return (*this);
}

//Getteurs
const std::string&	Koala::getSex() const
{
  return (this->_sex);
}

const std::string&	Koala::getName() const
{
  return (this->_name);
}

const std::string&	Koala::getPicture() const
{
  return (this->_picture);
}

int			Koala::getGenIndex() const
{
  return (_genIndex);
}

//random
int			Koala::random(int max)
{
  long                  to;

  to = ::random();
  return (to % max);
}

//Dumpeur

void			Koala::dumpAttributs() const
{
  std::cout << "[" << this->getName()<<"]" <<"Sex = "<< this->getSex()<< std::endl;
  std::cout << "[" << this->getName()<<"]" <<"Name = "<< this->getName()<< std::endl;
  std::cout << "[" << this->getName()<<"]" <<"GenIndex = "<< this->getGenIndex()<< std::endl;
  std::cout << "[" << this->getName()<<"]" <<"Picture ="<< std::endl;
  std::cout <<this->getPicture()<< std::endl;
}

//autres methode

void			Koala::eat(const std::string ingredient) const
{
  std::cout << "["<<this->getName()<<"] mange ["<< ingredient <<"]" << std::endl;
}

Koala*			Koala::procreate(const Koala& mate) const
{
  if (this->getSex() == mate.getSex())
    {
      std::cout << "Hey Dudes ... you're disgusting !" << std::endl;
      return (NULL);
    }
  else
    {

      if (this->getSex() != "male")
	{
	  Koala *baby =
	    new Koala(this->getSex(),
		      this->getName() + mate.getName(),
		      KoalaScii[this->getGenIndex()][mate.getGenIndex()],
		      this->getGenIndex());
	  return (baby);
	}
      else
	{
	  Koala *baby =
	    new Koala(this->getSex(),
		      this->getName() + mate.getName(),
		      KoalaScii[mate.getGenIndex()][this->getGenIndex()],
		      this->getGenIndex());
	  return (baby);
	}
    }
}
