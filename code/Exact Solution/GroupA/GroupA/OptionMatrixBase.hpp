#ifndef OPTIONMATRIXBASE_HPP
#define OPTIONMATRIXBASE_HPP

#include <vector>
#include "EuropeanOption.hpp"  // Include the header file for PlainOption or similar

class OptionMatrixBase
{
protected:
    vector<vector<double>> callOptionMatrix;
    vector<vector<double>> putOptionMatrix;
    PlainOption my_plainOption;

public:

    OptionMatrixBase();

    // Constructor with given option
    OptionMatrixBase(const PlainOption& newOption);

    // Copy constructor
    OptionMatrixBase(const OptionMatrixBase& omb2);

    virtual ~OptionMatrixBase();

    //Assignment operator
    OptionMatrixBase& operator = (const OptionMatrixBase& source);

    //Computes option matrices based on parameter matrix
    virtual void generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix) = 0;

    //Gets the call option matrix
    virtual vector<vector<double>> getCallOptionMatrix() const;

    //Gets the put option matrix
    virtual vector<vector<double>> getPutOptionMatrix() const;

    //Gets the option details
    virtual PlainOption getOptionDetails() const;

    //Prints the call option matrix to the console using iterators
    void printCallOptionMatrix() const;

    //Prints the put option matrix to the console using iterators
    void printPutOptionMatrix() const;
};

#endif