//
// BF_Translator.cpp for bf in /home/Anthony/Epitech/piscine/cpp/piscine/D09/ex_3
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Tue May 11 21:39:02 2010 anthony1 corbacho
// Last update Tue May 11 23:04:44 2010 anthony1 corbacho
//

#include        <string>
#include        <map>
#include        <iostream>
#include        <fstream>

#include "BF_Translator.h"

BF_Translator::BF_Translator()
{
  _Map['+'] = (char *)"(*ptr)++;\n";
  _Map['-'] = (char *)"(*ptr)--;\n";
  _Map['>'] = (char *)"ptr++;\n";
  _Map['<'] = (char *)"ptr--;\n";
  _Map['.'] = (char *)"write(1, ptr, 1);\n";
  _Map[','] = (char *)"read(0,ptr, 1);\n";
  _Map['['] = (char *)"while(*ptr != 0)\n{\n";
  _Map[']'] = (char *)"}\n";
  /*'-' => Decrement l'octet pointe
'>' => Avance le pointeur d'un octet
'<' => Recule le pointeur d'un octet
'.' => Affiche l'octet courant sur la sortie standard
',' => Lit un caractere sur l'entree standard et le stocke dans l'octet courant
'[' => Saute a l'instruction apres le ']' correspondant si l'octet pointe vaut 0
']' => Saute au '[' correspondant
  */
}

int		BF_Translator::translate(std::string in, std::string out)
{
  std::ifstream	fi;
  std::ofstream	fo;
  char		c;
  
  fi.open(in.c_str());
  fo.open(out.c_str());

  std::map<char, char *>::iterator ibegin;
  std::map<char, char *>::iterator iend = this->_Map.end();
  std::pair<char, char*> pr;
  if (fi.good() && fo.good())
    {
      fo << "#include <stdlib.h>\n#include <unistd.h>\n\nint main()\n{\n";
      fo << "char *ptr;\n ptr = malloc(60000 *sizeof(char));\n";
      while (!fi.eof())
	{
	  c = (char)fi.get();
	  ibegin = _Map.begin();
	  for ( ;ibegin != iend; ++ibegin)
	    {
	      pr = *ibegin;
	      if (c == pr.first)
		{
		  fo << pr.second;
		  break;
		}
	    }
	}
      fo << "return (0); \n}\n";
    }
  fi.close();
  fo.close();
  return 0;
}
