// OptionArray.cpp
#include "OptionArrayBase.hpp"
#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"

// Default constructor
OptionArrayBase::OptionArrayBase() 
{
}

//Constructor with given option
OptionArrayBase::OptionArrayBase(const PlainOption& newOption)
{
    my_plainOption = newOption;
}

//copy constructor
OptionArrayBase::OptionArrayBase(const OptionArrayBase& oab2)
{
    callOptionArray = oab2.callOptionArray;
    putOptionArray = oab2.putOptionArray;
    my_plainOption = oab2.my_plainOption;
}

// Destructor
OptionArrayBase::~OptionArrayBase() 
{

}

//Assignment operator
OptionArrayBase& OptionArrayBase::operator = (const OptionArrayBase& source)
{
    if (this == &source) return *this;

    callOptionArray = source.callOptionArray;
    putOptionArray = source.putOptionArray;
    my_plainOption = source.my_plainOption;

    return *this;
}


// Gets the call option array
vector<double> OptionArrayBase::getCallOptionArray() const 
{
    return callOptionArray;
}

// Gets the put option array
vector<double> OptionArrayBase::getPutOptionArray() const 
{
    return putOptionArray;
}

// Gets the option details
PlainOption OptionArrayBase::getOptionDetails() const 
{
    return my_plainOption;
}

void OptionArrayBase::printCallOptionArray() const 
{
    for (auto it = callOptionArray.begin(); it != callOptionArray.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void OptionArrayBase::printPutOptionArray() const
{
    for (auto it = putOptionArray.begin(); it != putOptionArray.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}