//
// main.cpp for main in /home/Anthony/Epitech/piscine/cpp/12h/ex_01
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Thu May 13 21:44:19 2010 anthony1 corbacho
// Last update Thu May 13 21:48:35 2010 anthony1 corbacho
//
#include "Stats.h"
#include "Knight.h"

int main()
{
  Stats*  stat;
  Knight  k("bronze cloth", 800, "Seya");

  std::cout << k << std::endl;
  k.powerDown(stat);
  stat = k.powerUp("gold cloth", 2000);

  std::cout << k << std::endl;
  while (k.getCosmos() > 0)
    k.attack("Pegasus Ryu Sei Ken", 500);

  k.powerDown(stat);
  std::cout << k << std::endl;
}
/*
Resultat attendus :
$>./a.out | cat -e
Knight Seya Armor : bronze cloth Cosmos : 800$
Knight Seya Armor : gold cloth Cosmos : 2000$
Seya : Pegasus Ryu Sei Ken$
Seya : Pegasus Ryu Sei Ken$
Seya : Pegasus Ryu Sei Ken$
Seya : Pegasus Ryu Sei Ken$
Used all cosmos, reverting to previous state$
	       Knight Seya Armor : bronze cloth Cosmos : 800$
*/
