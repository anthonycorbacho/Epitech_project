/*
 * IOperand.hpp
 *
 *  Created on: Jun 11, 2010
 *      Author: matt
 */

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include "IObject.hpp"

class IOperand : public IObject {
public:
    virtual IObject*  Add(const IOperand &object) = 0;          // Create a new object being the addition of the current instance and the parameter
    virtual IObject*  Subtract(const IOperand &object) = 0;     // Create a new object being the subtraction of the current instance and the parameter
    virtual IObject*  Multiply(const IOperand &object) = 0;     // Create a new object being the multiplication of the current instance and the parameter
    virtual IObject*  Divide(const IOperand &object) = 0;       // Create a new object being the division of the current instance and the parameter
};
#endif /* IOPERAND_HPP_ */
