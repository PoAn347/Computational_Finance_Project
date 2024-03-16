#include "OptionArrayDelta.hpp"
#include "EuropeanOption.hpp"  // Include the header file for PlainOption

// Default constructor
OptionArrayDelta::OptionArrayDelta() {}

// Constructor with given option
OptionArrayDelta::OptionArrayDelta(const PlainOption& option) : OptionArrayBase(option) {}

// Copy constructor
OptionArrayDelta::OptionArrayDelta(const OptionArrayDelta& oa2) : OptionArrayBase(oa2) {}

// Destructor
OptionArrayDelta::~OptionArrayDelta() {}

// Assignment operator
OptionArrayDelta& OptionArrayDelta::operator=(const OptionArrayDelta& source) 
{
    if (this == &source) 
    {
        return *this;
    }

    OptionArrayBase::operator=(source);

    return *this;
}

// Computes call and put option delta based on stock
void OptionArrayDelta::generateOptionArrays(const vector<double>& stockArray) 
{
    //Using each stock price in stock array to calculate the call and put price and place it in the array
    for (auto it = stockArray.begin(); it != stockArray.end(); ++it)
    {
        my_plainOption.Stock(*it);

        double CallOptionDelta = my_plainOption.GetCallDelta();
        double PutOptionDelta = my_plainOption.GetPutDelta();

        callOptionArray.push_back(CallOptionDelta);
        putOptionArray.push_back(PutOptionDelta);
    }
}
