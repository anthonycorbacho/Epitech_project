/*
** stringDemystificator.h for stringDemystificator in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue May 11 12:38:25 2010 anthony1 corbacho
** Last update Tue May 11 13:44:54 2010 anthony1 corbacho
*/

#ifndef __STRINGDEMYSTIFICATOR_H__
#define __STRINGDEMYSTIFICATOR_H__

#include <iostream>
#include <string>

class		stringDemystificator
{
 public:
  // constructeurs
  stringDemystificator();
  stringDemystificator(const std::string&);
  stringDemystificator(const char*);
  stringDemystificator(const stringDemystificator&);
  ~stringDemystificator();
  
  //methodes
  // Un magnifique operateur d'affectation:
  stringDemystificator&     operator =(const stringDemystificator&);

  // Supprime les espaces et les tabulations au debut
  // et a la fin de la chaine stockee.
  void          trim(void); 

  // Assigne la chaine "KREOG!" au debut de la chaine stockee, et ajoute
  // "KREOG!" a la fin.
  // Si la chaine est trop courte, ne tronquez pas KREOG!. La STL vous
  // fournit des strings extensibles.
  // Avant -> 'Un codeur sachant coder'
  // Apres -> 'KREOG!eur sachant coderKREOG!'
  // Avant -> 'Gnn?'
  // Apres -> 'KREOG!KREOG!'
  void          kreogize(void);     

  // Pas besoin de faire un dessin... 
  void          setString(const std::string&); 
  std::string	getString() const;
  // Si la chaine passee en parametre est inferieure a la chaine stockee,
  // elle est ajoutee a la fin de la chaine stockee.
  // Sinon elle est ajoutee au debut.
  // On utilise pour ca une comparaison lexicographique (cf strcmp(3))
  void          assemble(const std::string&);  
                                                    
  // Le systeme qui va bien pour pouvoir balancer la chaine contenue dans
  //  un ostream avec l'operateur <<.
  friend std::ostream&		operator <<(std::ostream &, const stringDemystificator&);

 private:
  std::string		_Say;
};

#endif /*__STRINGDEMYSTIFICATOR_H__*/
