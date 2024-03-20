// OptionMatrixGamma.cpp
#include "OptionMatrixGamma.hpp"
#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"

// Default constructor
OptionMatrixGamma::OptionMatrixGamma() : OptionMatrixBase()
{
    // cout << "default Option Gamma Matrix" << endl;
}

// Constructor with given option
OptionMatrixGamma::OptionMatrixGamma(const PlainOption& newOption) : OptionMatrixBase(newOption)
{
    // cout << "given value Option Gamma Matrix" << endl;
    // my_plainOption = newOption;
}

// Copy constructor
OptionMatrixGamma::OptionMatrixGamma(const OptionMatrixGamma& om2) : OptionMatrixBase(om2)
{
    callOptionMatrix = om2.callOptionMatrix;
    putOptionMatrix = om2.putOptionMatrix;
    my_plainOption = om2.my_plainOption;
}

// Destructor
OptionMatrixGamma::~OptionMatrixGamma() {}

// Assignment operator
OptionMatrixGamma& OptionMatrixGamma::operator= (const OptionMatrixGamma& source)
{
    if (this == &source)
    {
        return *this;
    }

    // Call the base class assignment operator
    OptionMatrixBase::operator=(source);

    return *this;
}

void OptionMatrixGamma::generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix)
{
    callOptionMatrix.clear();
    putOptionMatrix.clear();

    string parameterName1 = parameterNames.first;
    string parameterName2 = parameterNames.second;

    for (auto row_it = parametermatrix.begin(); row_it != parametermatrix.end(); ++row_it)
    {
        vector<double> RowCallOptionGammaArray;
        vector<double> RowPutOptionGammaArray;

        double parameter1 = (*row_it)[0].first; // Accessing the first element of the first pair in the vector

        // Call the appropriate setter function based on the parameter name
        if (parameterName1 == "Stock")
        {
            my_plainOption.Stock(parameter1);
        }
        else if (parameterName1 == "Time")
        {
            my_plainOption.Time(parameter1);
        }
        else if (parameterName1 == "Volatility")
        {
            my_plainOption.Volatility(parameter1);
        }
        else if (parameterName1 == "Strike")
        {
            my_plainOption.Strike(parameter1);
        }
        else if (parameterName1 == "RiskFree")
        {
            my_plainOption.RiskFree(parameter1);
        }
        else
        {
            // Default Stock Price
            my_plainOption.Stock(parameter1);
        }

        for (auto v_it = row_it->begin(); v_it != row_it->end(); ++v_it)
        {
            double parameter2 = v_it->second;

            // Call the appropriate setter function based on the parameter name
            if (parameterName2 == "Stock")
            {
                my_plainOption.Stock(parameter2);
            }
            else if (parameterName2 == "Time")
            {
                my_plainOption.Time(parameter2);
            }
            else if (parameterName2 == "Volatility")
            {
                my_plainOption.Volatility(parameter2);
            }
            else if (parameterName2 == "Strike")
            {
                my_plainOption.Strike(parameter2);
            }
            else if (parameterName2 == "RiskFree")
            {
                my_plainOption.RiskFree(parameter2);
            }
            else
            {
                my_plainOption.Time(parameter2); // Default 2p is Time
            }

            double CallOptionGamma = my_plainOption.GetCallGamma();
            double PutOptionGamma = my_plainOption.GetPutGamma();

            RowCallOptionGammaArray.push_back(CallOptionGamma);
            RowPutOptionGammaArray.push_back(PutOptionGamma);
        }

        callOptionMatrix.push_back(RowCallOptionGammaArray);
        putOptionMatrix.push_back(RowPutOptionGammaArray);
    }

    cout << endl;
}