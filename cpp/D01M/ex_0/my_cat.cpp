//
// my_cat.cpp for my_cat in /home/corbac_b/work/piscine/cpp/D01M/ex_0
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 10:08:24 2010 anthony1 corbacho
// Last update Mon May  3 12:06:16 2010 anthony1 corbacho
//
#include	<iostream>
#include	<fstream>
using	namespace	std;

void		cat_fic(int ac, char **av)
{
  char		buffer;
  int		c;

  c = 1;
  while (c < ac)
    {
      ifstream	fic_open;
      fic_open.open(av[c]);
      if (fic_open.good())
      {	
	while (!fic_open.eof())
	  {
	    
	    buffer = (char) fic_open.get();
	    if (buffer != -1)
	      cout << buffer;
	  }
      }
      else
	cout << "my_cat: " << av[c] << ": No such file or directory" << endl;
      fic_open.close();
      c++;
    }
}

int		main(int argc, char **argv)
{
  char		buffer;
  int		comp;

  if (argc < 2)
    {
      comp = 1;
      while (comp == 1)
	{
	  comp = 0;
	  buffer = (char) cin.get();
	  if (buffer != -1)
	    {
	      cout << buffer;
	      comp = 1;
	    }
	}
      return (1);
    }
  else
    cat_fic(argc, argv);
  return (1);
}

