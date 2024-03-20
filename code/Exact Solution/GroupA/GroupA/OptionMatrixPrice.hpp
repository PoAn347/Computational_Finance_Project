#ifndef OPTIONMATRIXPRICE_HPP
#define OPTIONMATRIXPRICE_HPP

#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"  // Include the header file for PlainOption
#include "OptionMatrixBase.hpp"

using namespace std;


class OptionMatrixPrice : public OptionMatrixBase
{
public:

    //Default constructor
    OptionMatrixPrice();

    //Constructor with given option
    OptionMatrixPrice(const PlainOption& option);

    //copy constructor
    OptionMatrixPrice(const OptionMatrixPrice& oa2);

    //Destructor
    virtual ~OptionMatrixPrice();

    //Assignment operator
    OptionMatrixPrice& operator = (const OptionMatrixPrice& source);

    //Computes call and put option price based on stock
    void generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix);

    //Get function for Call Price Matrix
    //vector<vector<double>> CallPriceMatrix() const;

    //Get function for Put Price Matrix
    //vector<vector<double>> PutPriceMatrix() const;

    //Print the matrix to the console using iterators
    //void PrintCallPriceMatrix() const;

    //Print the matrix to the console using iterators
    //void PrintPutPriceMatrix() const;
};


#endif