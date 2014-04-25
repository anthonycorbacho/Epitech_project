/*
 * Factory.h
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "LibLoader.h"
#include <string>
#include "IObject.hpp"
#include <map>

class Factory
{
public:

	void LoadDir(const std::string &path);
	IObject *clone(const std::string &type);

private:
	LibLoader _libLoad;
	std::map<std::string, IObject*> _mapObject;
};

#endif /* FACTORY_H_ */
