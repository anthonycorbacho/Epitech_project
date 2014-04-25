#ifndef	_DARKOALA_H_
#define _DARKOALA_H_

#include <iostream>
class	Darkoala
{
public:
	virtual	void	TakeLightSaber() const = 0;
	virtual	void	UseForce() const = 0;
	virtual	void	Breath() const = 0;
    virtual ~Darkoala() {};
	void	Jump()
	{
		std::cout << "Jump" << std::endl;
	}
};

#endif /*_DARKOALA_H_*/
