// OptionMatrixDelta.hpp
#ifndef OPTIONMATRIXDELTA_HPP
#define OPTIONMATRIXDELTA_HPP

#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"  // Include the header file for PlainOption
#include "OptionMatrixBase.hpp"

class OptionMatrixDelta : public OptionMatrixBase
{
public:

    // Default constructor
    OptionMatrixDelta();

    // Constructor with given option
    OptionMatrixDelta(const PlainOption& option);

    // Copy constructor
    OptionMatrixDelta(const OptionMatrixDelta& om2);

    // Destructor
    virtual ~OptionMatrixDelta();

    // Assignment operator
    OptionMatrixDelta& operator = (const OptionMatrixDelta& source);

    // Computes call and put option delta based on stock
    void generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix);

    // Get function for Call Delta Matrix
    // vector<vector<double>> CallDeltaMatrix() const;

    // Get function for Put Delta Matrix
    // vector<vector<double>> PutDeltaMatrix() const;

    // Print the matrix to the console using iterators
    // void PrintCallDeltaMatrix() const;

    // Print the matrix to the console using iterators
    // void PrintPutDeltaMatrix() const;
};

#endif