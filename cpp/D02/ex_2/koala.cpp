//
// koala.cpp for koala methodes in /home/corbac_b/work/piscine/cpp/D02/ex_2
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 11:00:44 2010 anthony1 corbacho
// Last update Tue May  4 23:30:53 2010 anthony1 corbacho
//

#include	<iostream>
#include	<stdlib.h>
#include	"constants.h"
#include	"koala.h"

using	namespace	std;

Koala::Koala(const char	*name)
{
  _Name = name;
  _Partner = NULL;
  if (strcmp("save", name) != 0)
    cout << "Kreog " << name << "! :D" << endl;
}

Koala::Koala(const char *name, Koala *koala)
{
  _Name = name;
  cout << "Kreog " << name << "! :D" << endl;
  _Partner = koala;
}

Koala::~Koala()
{
  cout << "Goerk " << this->GetName() << "! X[" << endl;
  
  if (_Partner != NULL)
    {
      Koala	*save;
      save = &this->GetPartner();
      while (this != save->_Partner)
	save = &save->GetPartner();
      save->_Partner = &this->GetPartner();
    }
  /*if (&this->_Partner->GetPartner() != this)
    {
      if (&this->GetPartner() != NULL)
	{
	  Koala *save = this;
	  while (&save->GetPartner() != &this->GetPartner())
	    save->SetPartner(&this->GetPartner());
	  save->SetPartner(&this->GetPartner());
	}
    }
  else
  this->_Partner = NULL;*/
}

// Setteur & Getteur
void		Koala::SetPartner(Koala *koala)
{
  this->_Partner = koala;
}

Koala		&Koala::GetPartner()
{
  if (this->_Partner == NULL)
    return(NULL_KOALA);
  else
    return (*this->_Partner);
}

const char	*Koala::GetName()
{
  return(this->_Name);
}

void		Koala::AddPartner(const char *name)
{

  if (this->_Partner == NULL)
    {
      Koala	*k = new Koala(name, this);
      this->_Partner = k;
    }
  else
    {
      Koala	*k = new Koala(name, this->_Partner);
      this->_Partner = k;
    }
  /*  Koala		*new_koala;
  
  if ((&this->GetPartner()) == NULL)
    new_koala = new Koala(name, this);
  else
    new_koala = new Koala(name, _Partner);
    this->SetPartner(new_koala);*/
}

void		Koala::DANCE()
{
  int		cpt;
  int		inc;
  Koala		*save;

  cpt = 0;
  inc = 0;
  save = this;
  while (SONG[cpt])
    cpt++;
  if (&save->GetPartner() != NULL)
    {
      while (inc < 12)
	{
	  cout << save->GetName() << ": "<< SONG[inc] << endl;
	  save = &save->GetPartner();
	  inc++;
	}
    }
  else
    {
      while (inc < 12)
	{
	  cout << save->GetName() << ": "<< SONG[inc] << endl;
	  inc++;
	}
    }
}

void		Koala::KillPartner()
{

  if (this->_Partner != NULL)
    {
      Koala	*save;
      save = &this->GetPartner();
      _Partner = &_Partner->GetPartner();
      save->_Partner = NULL;
      delete(save);
      if (this->_Partner == this)
	this->_Partner = NULL;
    }
  /*  if (this->_Partner != NULL)
    {
      Koala *k_save = new Koala("save");
      k_save = this->_Partner;
      delete(this->_Partner);
      if (k_save->_Partner != NULL)
	  this->SetPartner(k_save->_Partner);
      else
	this->SetPartner(NULL);
	}*/
}
