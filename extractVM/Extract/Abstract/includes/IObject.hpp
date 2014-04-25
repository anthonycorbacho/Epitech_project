/*
 * IObject.hpp
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_
#include <string>

class IObject
{
public:
    virtual const std::string&   ToString() const = 0;                    // Get a string representation of the object.
    virtual const std::string&   GetType() const = 0;                     // Get the type of the object.
    virtual bool            Equals(const IObject &value) const = 0;  // Returns true if the given type and content are equal.
    virtual IObject*        Clone() const = 0;                       // Create a new instance by making a deep copy of the current object data.
};

#endif /* IOBJECT_HPP_ */
