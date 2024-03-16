#ifndef OPTIONARRAYBASE_HPP
#define OPTIONARRAYBASE_HPP

#include <vector>
#include "AmericanOption.hpp"  // Include the header file for PlainOption or similar

class OptionArrayBase 
{
protected:
    //Vector to store call option prices for each stock
    std::vector<double> callOptionArray;

    //Vector to store put option prices for each stock
    std::vector<double> putOptionArray;

    //Perpetual American option object used for calculations
    PerpetualAmericanOption my_PerpetualAmericanOption;

public:
    //Default constructor
    OptionArrayBase();

    //Constructor with given perpetual American option
    OptionArrayBase(const PerpetualAmericanOption& newOption);

    //Copy constructor
    OptionArrayBase(const OptionArrayBase& oab2);

    // Destructor
    virtual ~OptionArrayBase();

    //Assignment operator
    OptionArrayBase& operator=(const OptionArrayBase& source);

    //Computes option arrays based on an array of stock prices. The pure virtual function is declared in this base class and will be implemented by derived classes. 
    //It takes a vector of stock prices as input and calculates the corresponding call and put option prices for each stock price, populating the callOptionArray and putOptionArray.
    virtual void generateOptionArrays(const std::vector<double>& stockArray) = 0;

    //Gets the call option array
    virtual std::vector<double> getCallOptionArray() const;

    //Gets the put option array
    virtual std::vector<double> getPutOptionArray() const;

    //Gets the details of the perpetual American option
    virtual PerpetualAmericanOption getOptionDetails() const;

    //Prints the call option array to the console
    void printCallOptionArray() const;

    //Prints the put option array to the console
    void printPutOptionArray() const;
};

#endif