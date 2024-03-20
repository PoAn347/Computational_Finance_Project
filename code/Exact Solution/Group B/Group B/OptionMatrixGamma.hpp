// OptionMatrixGamma.hpp
#ifndef OPTIONMATRIXGAMMA_HPP
#define OPTIONMATRIXGAMMA_HPP

#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"  // Include the header file for PlainOption
#include "OptionMatrixBase.hpp"

class OptionMatrixGamma : public OptionMatrixBase
{
public:

    // Default constructor
    OptionMatrixGamma();

    // Constructor with given option
    OptionMatrixGamma(const PlainOption& option);

    // Copy constructor
    OptionMatrixGamma(const OptionMatrixGamma& om2);

    // Destructor
    virtual ~OptionMatrixGamma();

    // Assignment operator
    OptionMatrixGamma& operator = (const OptionMatrixGamma& source);

    // Computes call and put option gamma based on stock
    void generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix);

    // Get function for Call Gamma Matrix
    // vector<vector<double>> CallGammaMatrix() const;

    // Get function for Put Gamma Matrix
    // vector<vector<double>> PutGammaMatrix() const;

    // Print the matrix to the console using iterators
    // void PrintCallGammaMatrix() const;

    // Print the matrix to the console using iterators
    // void PrintPutGammaMatrix() const;
};

#endif