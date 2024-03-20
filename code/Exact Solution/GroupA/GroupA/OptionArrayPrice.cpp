// OptionArray.cpp
#include "OptionArrayPrice.hpp"
#include "EuropeanOption.hpp"


//Default constructor
OptionArrayPrice::OptionArrayPrice() : OptionArrayBase()
{
    //cout << "default Option array" << endl;
}

//Constructor with given option
OptionArrayPrice::OptionArrayPrice(const PlainOption& newOption) : OptionArrayBase(newOption)
{
    //cout << "given value Option array" << endl;
}


//copy constructor
OptionArrayPrice::OptionArrayPrice(const OptionArrayPrice& oa2) : OptionArrayBase(oa2)
{
}


//Destructor
OptionArrayPrice::~OptionArrayPrice() {}


//Assignment operator
OptionArrayPrice& OptionArrayPrice::operator= (const OptionArrayPrice& source)
{
    if (this == &source) 
    {
        return *this;
    }

    // Call the base class assignment operator
    OptionArrayBase::operator=(source);

    return *this;
}


void OptionArrayPrice::generateOptionArrays(const vector<double>& stockArray)
{

    //Using each stock price in stock array to calculate the call and put price and place it in the array
    for (auto it = stockArray.begin(); it != stockArray.end(); ++it)
    {   
        my_plainOption.Stock(*it);

        double CallOptionPrice = my_plainOption.GetCallPrice();
        double PutOptionPrice = my_plainOption.GetPutPrice();

        callOptionArray.push_back(CallOptionPrice);
        putOptionArray.push_back(PutOptionPrice);
    }

}

/*
//Get function for Call Price Array
vector<double> OptionArrayPrice::CallPriceArray() const
{
    return CallOptionPriceArray;
}

//Get function for Call Price Array
vector<double> OptionArrayPrice::PutPriceArray() const
{
    return PutOptionPriceArray;
}

void OptionArrayPrice::PrintCallPriceArray() const
{
    for (auto it = CallOptionPriceArray.begin(); it != CallOptionPriceArray.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void OptionArrayPrice::PrintPutPriceArray() const
{
    for (auto it = PutOptionPriceArray.begin(); it != PutOptionPriceArray.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
*/