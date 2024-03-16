#ifndef OPTIONARRAYPRICE_HPP
#define OPTIONARRAYPRICE_HPP

#include <vector>
#include <iostream>
#include "AmericanOption.hpp"  // Include the header file for PlainOption
#include "OptionArrayBase.hpp" 

using namespace std;


class OptionArrayPrice : public OptionArrayBase
{
public:
    
    // Default constructor
    OptionArrayPrice();

    // Constructor with given perpetual American option
    OptionArrayPrice(const PerpetualAmericanOption& newOption);

    // Copy constructor
    OptionArrayPrice(const OptionArrayPrice& oa2);

    // Destructor
    ~OptionArrayPrice();

    // Assignment operator
    OptionArrayPrice& operator=(const OptionArrayPrice& source);

    // Computes option arrays based on an array of stock prices
    void generateOptionArrays(const std::vector<double>& stockArray);

};


#endif