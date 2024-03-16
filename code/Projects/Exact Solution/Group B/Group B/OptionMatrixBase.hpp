#ifndef OPTIONMATRIXBASE_HPP
#define OPTIONMATRIXBASE_HPP

#include <vector>
#include "AmericanOption.hpp"  // Include the header file for PlainOption or similar

class OptionMatrixBase
{
protected:
    vector<vector<double>> callOptionMatrix;
    vector<vector<double>> putOptionMatrix;
    PerpetualAmericanOption my_PerpetualAmericanOption;

public:

    //Default Constructor
    OptionMatrixBase();

    //Constructor with given option
    OptionMatrixBase(const PerpetualAmericanOption& newOption);

    //Copy constructor
    OptionMatrixBase(const OptionMatrixBase& omb2);

    virtual ~OptionMatrixBase();

    //Assignment operator
    OptionMatrixBase& operator = (const OptionMatrixBase& source);

    //Computes option matrices based on parameter matrix. The pure virtual function is declared in this base class and will be implemented by derived classes. 
    virtual void generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix) = 0;

    //Gets the call option matrix
    virtual vector<vector<double>> getCallOptionMatrix() const;

    //Gets the put option matrix
    virtual vector<vector<double>> getPutOptionMatrix() const;

    //Gets the option details
    virtual PerpetualAmericanOption getOptionDetails() const;

    //Prints the call option matrix to the console using iterators
    void printCallOptionMatrix() const;

    //Prints the put option matrix to the console using iterators
    void printPutOptionMatrix() const;
};

#endif