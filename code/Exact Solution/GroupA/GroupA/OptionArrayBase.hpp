#ifndef OPTIONARRAYBASE_HPP
#define OPTIONARRAYBASE_HPP

#include <vector>
#include "EuropeanOption.hpp"  // Include the header file for PlainOption or similar

class OptionArrayBase 
{
protected:
    vector<double> callOptionArray;
    vector<double> putOptionArray;
    PlainOption my_plainOption; 

public:

    OptionArrayBase();

    //Constructor with given option
    OptionArrayBase(const PlainOption& newOption);

    //copy constructor
    OptionArrayBase(const OptionArrayBase& oab2);

    virtual ~OptionArrayBase();
    
    //Assignment operator
    OptionArrayBase& operator = (const OptionArrayBase& source);

    //Computes option arrays based on stock array
    virtual void generateOptionArrays(const vector<double>& stockArray) = 0;

    //Gets the call option array
    virtual vector<double> getCallOptionArray() const;

    // Gets the put option array
    virtual vector<double> getPutOptionArray() const;

    // Gets the option details
    virtual PlainOption getOptionDetails() const;

    void printCallOptionArray() const;
    void printPutOptionArray() const;
};

#endif