/*
** Bender.h for Bender in /home/corbac_b/work/piscine/cpp/D02/ex_5
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May  4 17:39:15 2010 anthony1 corbacho
** Last update Tue May  4 18:58:10 2010 anthony1 corbacho
*/

#ifndef		__BENDER_H__
#define		__BENDER_H__
class		Bender
{
 public:
  Bender();
  ~Bender();

  void		defaultBehaviour() const;
  void		loadInternalProgram() const;
  void		catchPhrase() const;
  void		blowUpThisEntirePlanet() const;
  void		meetHuman() const;
  void		behave() const;
  void		setBehaviour(void (Bender::*fct)() const);
 private:
  void		(Bender::*Param)() const;
};
#endif		//__BENDER_H__
