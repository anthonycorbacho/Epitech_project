#ifndef __INSTRUCTION__
#define __INSTRUCTION__

#include <string>

class Instruction
{
public:
	virtual ~Instruction();

	virtual std::string getKeyword() = 0;
	virtual void execute() = 0;
	virtual Instruction* clone() = 0;
	virtual bool analyse(std::string ope, std::string args) = 0;

	std::string extractType(const std::string args);
	void trim(std::string& str);
	void cutCommentary(std::string &);

protected:
	Instruction();
};

#endif //__INSTRUCTION__
