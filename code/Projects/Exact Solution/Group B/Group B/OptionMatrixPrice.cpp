//OptionMatrix.cpp
#include "OptionMatrixPrice.hpp"
#include <vector>
#include <iostream>
#include "AmericanOption.hpp"


//Default constructor
OptionMatrixPrice::OptionMatrixPrice() : OptionMatrixBase()
{
    //cout << "default Option Price Matrix" << endl;
}

//Constructor with given option
OptionMatrixPrice::OptionMatrixPrice(const PerpetualAmericanOption& newOption) : OptionMatrixBase(newOption)
{
    //cout << "given value Option Price Matrix" << endl;
    //my_plainOption = newOption;
}

//copy constructor
OptionMatrixPrice::OptionMatrixPrice(const OptionMatrixPrice& om2) : OptionMatrixBase(om2)
{
    callOptionMatrix = om2.callOptionMatrix;
    putOptionMatrix = om2.putOptionMatrix;
    my_PerpetualAmericanOption = om2.my_PerpetualAmericanOption;
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
            my_PerpetualAmericanOption.Stock(parameter1);
        }
        else if (parameterName1 == "Volatility")
        {
            my_PerpetualAmericanOption.Volatility(parameter1);
        }
        else if (parameterName1 == "Strike")
        {
            my_PerpetualAmericanOption.Strike(parameter1);
        }
        else if (parameterName1 == "RiskFree")
        {
            my_PerpetualAmericanOption.RiskFree(parameter1);
        }
        else if (parameterName1 == "CarryCost")
        {
            my_PerpetualAmericanOption.CarryCost(parameter1);
        }
        else
        {   
            //Default Stock Price
            my_PerpetualAmericanOption.Stock(parameter1);
        }

        for (auto v_it = row_it->begin(); v_it != row_it->end(); ++v_it)
        {
            double parameter2 = v_it->second;

            // Call the appropriate setter function based on the parameter name
            if (parameterName2 == "Stock")
            {
                my_PerpetualAmericanOption.Stock(parameter2);
            }
            else if (parameterName2 == "Volatility")
            {
                my_PerpetualAmericanOption.Volatility(parameter2);
            }
            else if (parameterName2 == "Strike")
            {
                my_PerpetualAmericanOption.Strike(parameter2);
            }
            else if (parameterName2 == "RiskFree")
            {
                my_PerpetualAmericanOption.RiskFree(parameter2);
            }
            else if (parameterName1 == "CarryCost")
            {
                my_PerpetualAmericanOption.CarryCost(parameter2);
            }
            else
            {
                //Default Strike Price
                my_PerpetualAmericanOption.Strike(parameter2);//Default 2p is Time
            }
            

            double CallOptionPrice = my_PerpetualAmericanOption.GetCallPrice();
            double PutOptionPrice = my_PerpetualAmericanOption.GetPutPrice();

            RowCallOptionPriceArray.push_back(CallOptionPrice);
            RowPutOptionPriceArray.push_back(PutOptionPrice);
        }

        callOptionMatrix.push_back(RowCallOptionPriceArray);
        putOptionMatrix.push_back(RowPutOptionPriceArray);
    }

    cout << endl;
}
