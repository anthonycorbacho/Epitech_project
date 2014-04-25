//
// M4.cpp for M4 in /home/Anthony/Epitech/piscine/cpp/24h/ex_06
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Fri May  7 02:23:02 2010 anthony1 corbacho
// Last update Fri May  7 14:09:46 2010 anthony1 corbacho
//

#include	<iostream>
#include	"M4.h"

M4::M4(int cap = 30) : _Scope(), _Mag(cap),  _Lp(), _Lcd(_Mag, _Scope, _Lp, *this)
{
  _isHand = 0;
  _setFire = 1;
}

void		M4::Take()
{
  this->_isHand = 1;
}

void		M4::Drop()
{
  this->_isHand = 0;
}

bool		M4::IsInHand() const
{
  if (this->_isHand == 0)
    return (0);
  return (1);
}

void		M4::SetFireRate(int nbBullet)
{
  this->_setFire = nbBullet;
}

int		M4::GetFireRate() const
{
  return (this->_setFire);
}

void		M4::Reload()
{
  M4::_Mag.Reload();
}

void		M4::Fire()
{
  for (int i = 0; i < this->GetFireRate(); i++)
    this->_Mag.RemoveOneBullet();
}


M4::LaserPointer::LaserPointer()
{
  _isActivate = 0;
}
void		M4::LaserPointer::Activate()
{
  this->_isActivate = 1;
}

void		M4::LaserPointer::Deactivate()
{
  this->_isActivate = 0;
}

bool		M4::LaserPointer::IsOn() const
{
  return (this->_isActivate);
}

M4::Scope::Scope()
{
  _isActivate = 0;
}

void		M4::Scope::Activate()
{
  this->_isActivate = 1;
}

void		M4::Scope::Deactivate()
{
  this->_isActivate = 0;
}

bool		M4::Scope::IsActive() const
{
  return (this->_isActivate);
}

M4::Magazine::Magazine()
{
}

M4::Magazine::Magazine(int cap)
{
  _cap = cap;
  _ammo = 0;
}

void		M4::Magazine::RemoveOneBullet()
{
  if (this->_ammo > 0)
  this->_ammo--;
  if (this->_ammo <= 0)
    this->_ammo = 0;
}

int		M4::Magazine::GetAmmo() const
{
  return (this->_ammo);
}

int		M4::Magazine::GetCapacity() const
{
  return (this->_cap);
}

void		M4::Magazine::Reload()
{
  this->_ammo = this->_cap;
}

M4::LCDScreen::LCDScreen(const Magazine& M, const Scope& S, const LaserPointer& lp, const M4& m4):
  m(M), s(S), l(lp), w(m4)
{
}

void		M4::LCDScreen::ShowCurrentState()
{
  std::cout << "State : " << std::endl;
  std::cout << "M4 in Hand : " << std::boolalpha << w.IsInHand() << std::endl;
  std::cout << "Ammo : " << m.GetAmmo() << "/" << m.GetCapacity() << std::endl;
  std::cout << "Scope Activated : " << s.IsActive() << std::endl;
  std::cout << "Laser Activated : " << l.IsOn() << std::endl;
}
