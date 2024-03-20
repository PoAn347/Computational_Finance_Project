// OptionMatrix.cpp
#include "OptionMatrixPrice.hpp"
#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"


//Default constructor
OptionMatrixPrice::OptionMatrixPrice() : OptionMatrixBase()
{
    //cout << "default Option Price Matrix" << endl;
}

//Constructor with given option
OptionMatrixPrice::OptionMatrixPrice(const PlainOption& newOption) : OptionMatrixBase(newOption)
{
    //cout << "given value Option Price Matrix" << endl;
    //my_plainOption = newOption;
}

//copy constructor
OptionMatrixPrice::OptionMatrixPrice(const OptionMatrixPrice& om2) : OptionMatrixBase(om2)
{
    callOptionMatrix = om2.callOptionMatrix;
    putOptionMatrix = om2.putOptionMatrix;
    my_plainOption = om2.my_plainOption;
}

//Destructor
OptionMatrixPrice::~OptionMatrixPrice() {}

//Assignment operator
OptionMatrixPrice& OptionMatrixPrice::operator= (const OptionMatrixPrice& source)
{
    if (this == &source)
    {
        return *this;
    }

    //Call the base class assignment operator
    OptionMatrixBase::operator=(source);
    

    return *this;
}


void OptionMatrixPrice::generatingOptionMatrices(const pair<string, string>& parameterNames, const vector<vector<pair<double,double>>>& parametermatrix)
{   
    callOptionMatrix.clear();
    putOptionMatrix.clear();

    string parameterName1 = parameterNames.first;
    string parameterName2 = parameterNames.second;

    for (auto row_it = parametermatrix.begin(); row_it!= parametermatrix.end(); ++row_it)
    {
        vector<double> RowCallOptionPriceArray;
        vector<double> RowPutOptionPriceArray;

        double parameter1 = (*row_it)[0].first;// Accessing the first element of the first pair in the vector

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
            //Default Stock Price
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
                //Default 2p is Time
                my_plainOption.Time(parameter2);
            }
            

            double CallOptionPrice = my_plainOption.GetCallPrice();
            double PutOptionPrice = my_plainOption.GetPutPrice();

            RowCallOptionPriceArray.push_back(CallOptionPrice);
            RowPutOptionPriceArray.push_back(PutOptionPrice);
        }

        callOptionMatrix.push_back(RowCallOptionPriceArray);
        putOptionMatrix.push_back(RowPutOptionPriceArray);
    }

    cout << endl;
}

/*
//Get function for Call Price Matrix
vector<vector<double>> OptionMatrixPrice::CallPriceMatrix() const
{
    return CallOptionPriceMatrix;
}

//Get function for Call Price Matrix
vector<vector<double>> OptionMatrixPrice::PutPriceMatrix() const
{
    return PutOptionPriceMatrix;
}

//Print the matrix to the console using iterators
void OptionMatrixPrice::PrintCallPriceMatrix() const
{
    for (auto row_it = CallOptionPriceMatrix.begin(); row_it != CallOptionPriceMatrix.end(); ++row_it)
    {
        for (auto value_it = row_it->begin(); value_it != row_it->end(); ++value_it)
        {
            cout << *value_it << "  " << "\t";
        }
        cout << endl;
    }
}

//Print the matrix to the console using iterators
void OptionMatrixPrice::PrintPutPriceMatrix() const
{
    for (auto row_it = PutOptionPriceMatrix.begin(); row_it != PutOptionPriceMatrix.end(); ++row_it)
    {   
        for (auto value_it = row_it->begin(); value_it != row_it->end(); ++value_it)
        {   
            cout << *value_it << "  " << "\t";
        }
        cout << endl;
    }
}
*/