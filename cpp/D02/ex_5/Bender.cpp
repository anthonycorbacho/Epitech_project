//
// Bender.cpp for Bender in /home/corbac_b/work/piscine/cpp/D02/ex_5
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May  4 17:48:05 2010 anthony1 corbacho
// Last update Tue May  4 23:42:43 2010 anthony1 corbacho
//

#include	"Bender.h"
#include	"Alcohol.h"
#include	<iostream>

Bender::Bender()
{
  setBehaviour(&Bender::defaultBehaviour);
}

Bender::~Bender()
{
}

void	Bender::defaultBehaviour() const
{
  std::cout << "I am Bender, please insert girder..."<< std::endl;
}

void	Bender::loadInternalProgram() const
{
  std::cout << "I am Bender, please insert liquor !"<< std::endl;
}

void	Bender::catchPhrase() const
{
  std::cout << "Bite my shiny metal ass !"<< std::endl;
}

void	Bender::blowUpThisEntirePlanet() const
{
  std::cout << "Bite MY Shiny Daffodil Ass !"<< std::endl;
}

void	Bender::meetHuman() const
{
  std::cout << "Hey there meetbag !"<< std::endl;
}

void	Bender::setBehaviour(void (Bender::*fct)() const)
{
  this->Param = fct;
}

void	Bender::behave() const
{

  Alcohol	alc;

  if (alc.getAvailebleAlcohol() == 0)
    std::cout << "Hey baby ! Bender need liquor !" << std::endl;
  else
    {
      (this->*Param)();  
      alc->getAvailebleAlcohol() -= 1;
    }
}
