// OptionArray.cpp
#include "OptionArrayBase.hpp"
#include <vector>
#include <iostream>
#include "AmericanOption.hpp"

// Default constructor
OptionArrayBase::OptionArrayBase() 
{
}

//Constructor with given option
OptionArrayBase::OptionArrayBase(const PerpetualAmericanOption& newOption)
{
    my_PerpetualAmericanOption = newOption;
}

//copy constructor
OptionArrayBase::OptionArrayBase(const OptionArrayBase& oab2)
{
    callOptionArray = oab2.callOptionArray;
    putOptionArray = oab2.putOptionArray;
    my_PerpetualAmericanOption = oab2.my_PerpetualAmericanOption;
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
    my_PerpetualAmericanOption = source.my_PerpetualAmericanOption;

    return *this;
}


//Gets the call option array
vector<double> OptionArrayBase::getCallOptionArray() const 
{
    return callOptionArray;
}

//Gets the put option array
vector<double> OptionArrayBase::getPutOptionArray() const 
{
    return putOptionArray;
}

//Gets the option object
PerpetualAmericanOption OptionArrayBase::getOptionDetails() const
{
    return my_PerpetualAmericanOption;
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