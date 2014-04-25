/*
 * LibLoader.h
 *
 *  Created on: Jun 6, 2010
 *      Author: matt
 */

#ifndef LIBLOADER_H_
#define LIBLOADER_H_

#include <string>
#include <map>
#include "myException.h"

class LibLoader
{
public:
	LibLoader();

	/*
	 * Loads a library from a specified path
	 */
	void *loadFromPath(const std::string &path);

	/*
	 * Unloads the library from this path
	 */
	void unloadFromPath(const std::string &path);

	/*
	 * Unloads the library from this path
	 */
	void unloadFromInputPoint(void *input);

	/*
	 * Returns the address of a specified symbol in a lib already opened
	 */
	void *getSym(void *inputPoint, const std::string &symName);

	/*
	 * returns an entry point corresponding to he specified path
	 */
	void *getFromPath(const std::string &path) const;

	virtual ~LibLoader();

	void loadDirectory(const std::string &path);
private:
	void addSuffix(std::string &path) const;
	bool suffixMatch(const std::string &filename) const;

	std::map<void *, std::string> _libs;
	friend class Factory;
	friend class PrototypeInstruction;
};

#endif /* LIBLOADER_H_ */
