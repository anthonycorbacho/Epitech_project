#ifndef __PARSSEUR__
#define __PARSSEUR__

#include <istream>
#include <fstream>
#include <map>

#include "Factory.h"
#include "instruction.hpp"
#include "PrototypeInstruction.h"

class Parsing
{
	friend class Instruction;
public:
	Parsing(std::string);
	~Parsing();
	Instruction* getNextInstruction();
	void Load();
private:
	void epureLine(std::string &line);
	void cleanTrim(std::string &str);
	std::string getKeyword(std::string &line);

	std::fstream _file; /*Handler on the file we are parsing*/
	PrototypeInstruction _protoInstr; /*Prototype which will clone the needed instructions*/
};

#endif //__PARSSEUR__
