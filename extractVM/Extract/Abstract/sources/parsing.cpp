#include "parsing.hpp"
#include "myException.h"
#include <iostream>

Parsing::Parsing(std::string path) :
	_protoInstr()
{
	_file.open(path.c_str());
	if (_file.is_open())
	{
		std::cout << "File: " << path << " correctly opened" << std::endl;
	}
	else
		throw(MyException("Impossible d'ouvrir le fichier"));
	_protoInstr.LoadInstr();
}

Parsing::~Parsing()
{
}

void Parsing::cleanTrim(std::string &str)
{
	std::string::size_type pos1 = str.find_first_not_of(" \t\n\r");
	std::string::size_type pos2 = str.find_last_not_of(" \t\n\r");
	str = str.substr(pos1 == std::string::npos ? 0 : pos1, 
		pos2 == std::string::npos ? str.length() - 1 : pos2 - pos1 + 1);
}


Instruction* Parsing::getNextInstruction()
{
	char buff[255];
	if (_file.good())
	{
		_file.getline(buff, 255);
		std::string line(buff);
		cleanTrim(line);
		epureLine(line);
		std::string keyword = getKeyword(line);
		if (!keyword.size())
			return (this->getNextInstruction());
		Instruction *ins;
		try
		{
			ins = _protoInstr.cloneInstruction(keyword, line.substr(keyword.size()));
			return (ins);
		} catch (MyException e)
		{
			std::cout << "Catching exception in getNextinstruction: "
					<< e.what() << std::endl;
			if (e.getNum() == 1)
			{
				//TODO differencier les exceptions
			}
		}
	}
	return NULL;
}

void Parsing::epureLine(std::string &line)
{
	size_t found = line.find_first_of(";");
	if (found != std::string::npos)
		line = line.substr(0, found);
}

std::string Parsing::getKeyword(std::string &line)
{
	size_t beg = line.find_first_not_of(" \t\n\r");
	if (beg != std::string::npos)
	{
		size_t end = line.find_first_of(" \t\n\r", beg);
		if (end != std::string::npos)
			return std::string(line.substr(beg, end - beg));
		else
			return std::string(line.substr(beg));
	}
	else
		return (std::string(""));
}
