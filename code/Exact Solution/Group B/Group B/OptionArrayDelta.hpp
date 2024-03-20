#ifndef OPTIONARRAYDELTA_HPP
#define OPTIONARRAYDELTA_HPP

#include <vector>
#include <iostream>
#include "EuropeanOption.hpp" 
#include "OptionArrayBase.hpp"

class OptionArrayDelta : public OptionArrayBase 
{
public:
    // Default constructor
    OptionArrayDelta();

    // Constructor with given option
    OptionArrayDelta(const PlainOption& option);

    // Copy constructor
    OptionArrayDelta(const OptionArrayDelta& oa2);

    // Destructor
    virtual ~OptionArrayDelta();

    // Assignment operator
    OptionArrayDelta& operator=(const OptionArrayDelta& source);

    // Computes call and put option delta based on stock
    void generateOptionArrays(const vector<double>& stockArray);

};

#endif