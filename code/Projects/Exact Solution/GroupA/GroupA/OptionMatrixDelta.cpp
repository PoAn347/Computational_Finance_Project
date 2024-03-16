
// OptionMatrixDelta.cpp
#include "OptionMatrixDelta.hpp"
#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"

// Default constructor
OptionMatrixDelta::OptionMatrixDelta() : OptionMatrixBase()
{
    // cout << "default Option Delta Matrix" << endl;
}

// Constructor with given option
OptionMatrixDelta::OptionMatrixDelta(const PlainOption& newOption) : OptionMatrixBase(newOption)
{
    // cout << "given value Option Delta Matrix" << endl;
    // my_plainOption = newOption;
}

// Copy constructor
OptionMatrixDelta::OptionMatrixDelta(const OptionMatrixDelta& om2) : OptionMatrixBase(om2)
{
    callOptionMatrix = om2.callOptionMatrix;
    putOptionMatrix = om2.putOptionMatrix;
    my_plainOption = om2.my_plainOption;
}

// Destructor
OptionMatrixDelta::~OptionMatrixDelta() {}

// Assignment operator
OptionMatrixDelta& OptionMatrixDelta::operator= (const OptionMatrixDelta& source)
{
    if (this == &source)
    {
        return *this;
    }

    // Call the base class assignment operator
    OptionMatrixBase::operator=(source);

    return *this;
}

void OptionMatrixDelta::generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double, double>>>& parametermatrix)
{
    callOptionMatrix.clear();
    putOptionMatrix.clear();

    string parameterName1 = parameterNames.first;
    string parameterName2 = parameterNames.second;

    for (auto row_it = parametermatrix.begin(); row_it != parametermatrix.end(); ++row_it)
    {
        vector<double> RowCallOptionDeltaArray;
        vector<double> RowPutOptionDeltaArray;

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

            double CallOptionDelta = my_plainOption.GetCallDelta();
            double PutOptionDelta = my_plainOption.GetPutDelta();

            RowCallOptionDeltaArray.push_back(CallOptionDelta);
            RowPutOptionDeltaArray.push_back(PutOptionDelta);
        }

        callOptionMatrix.push_back(RowCallOptionDeltaArray);
        putOptionMatrix.push_back(RowPutOptionDeltaArray);
    }

    cout << endl;
}