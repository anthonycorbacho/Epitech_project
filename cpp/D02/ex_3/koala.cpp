//
// koala.cpp for koala in /home/corbac_b/work/piscine/cpp/D02/ex_3
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 15:16:40 2010 anthony1 corbacho
// Last update Tue May  4 20:50:05 2010 anthony1 corbacho
//

#include	<iostream>
#include	"koala.h"

Koala::Koala()
{
  _Name = 0;
  _Children = 0;
  _NbChild = 0;
  _IsDaddy = 0;
  std::cout << "Kreog! :D" << std::endl;
}

Koala::~Koala()
{
  if(this->_Name == 0)
    std::cout << "Goerk! X[" << std::endl;
  else
    std::cout << "Goerk " << this->Name() << "! X[" << std::endl;
  delete [] this->_Children;
}

char		*&Koala::Name()
{
  return(this->_Name);
}

void		Koala::CreateChildren(int children)
{
  int		cpt;
  
  cpt = 0;
  if (this->_Children != 0)
    delete[] _Children;
  if (children > 0)
    {
      this->_Children = new Koala[children];
      while (cpt < children)
	{
	  this->_Children[cpt]._IsDaddy = this;
	  cpt++;
	}
      this->_NbChild = children;
    }
  else
    {
      _Children = 0;
      this->_NbChild = 0;
    }
}

Koala		&Koala::GetChild(int children)
{
  return(this->_Children[children]);
}

int		Koala::GetChildrenCount()
{
  int		cpt;
  int		total;

  cpt = 0;
  total = this->_NbChild;
  while (cpt < this->_NbChild)
    {
      total += this->_Children[cpt].GetChildrenCount();
      cpt++;
    }
  return (total);
}

void		Koala::WhoIsYourDaddy()
{
 
  if (this->_Name != 0) 
    {
      if (strcmp(this->_Name, "Jenna Haze") == 0)
	{
	  std::cout << "It's Kerdrek! :D" << std::endl;
	  return;
	}
    }
  else 
    if (this->_IsDaddy != 0)
      std::cout << this->_IsDaddy->Name() << std::endl;
}
