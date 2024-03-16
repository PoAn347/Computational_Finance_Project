#include "OptionMatrixBase.hpp"
#include "AmericanOption.hpp"
#include <iostream>

OptionMatrixBase::OptionMatrixBase()
{
}

OptionMatrixBase::OptionMatrixBase(const PerpetualAmericanOption& newOption)
{
    my_PerpetualAmericanOption = newOption;
}

OptionMatrixBase::OptionMatrixBase(const OptionMatrixBase& omb2) 
{
    callOptionMatrix = omb2.callOptionMatrix;
    putOptionMatrix = omb2.putOptionMatrix;
    my_PerpetualAmericanOption = omb2.my_PerpetualAmericanOption;
}

OptionMatrixBase::~OptionMatrixBase() 
{
    // Cleanup resources if needed
}

OptionMatrixBase& OptionMatrixBase::operator=(const OptionMatrixBase& source) 
{
   
    if (this == &source) 
    {
        return *this;
    }

    callOptionMatrix = source.callOptionMatrix;
    putOptionMatrix = source.putOptionMatrix;
    my_PerpetualAmericanOption = source.my_PerpetualAmericanOption;

    return *this;
}

vector<vector<double>> OptionMatrixBase::getCallOptionMatrix() const 
{
    return callOptionMatrix;
}

vector<vector<double>> OptionMatrixBase::getPutOptionMatrix() const 
{
    return putOptionMatrix;
}

PerpetualAmericanOption OptionMatrixBase::getOptionDetails() const
{
    return my_PerpetualAmericanOption;
}

void OptionMatrixBase::printCallOptionMatrix() const 
{
    cout << "Call Option Matrix:" << endl;

    for (auto row_it = callOptionMatrix.begin(); row_it != callOptionMatrix.end(); ++row_it)
    {
        for (auto value_it = row_it->begin(); value_it != row_it->end(); ++value_it)
        {
            cout << *value_it << "   " << "\t";
        }
        cout << endl;
    }
}

void OptionMatrixBase::printPutOptionMatrix() const 
{
    
    cout << "Put Option Matrix:" << endl;
    
    for (auto row_it = putOptionMatrix.begin(); row_it != putOptionMatrix.end(); ++row_it)
    {
        for (auto value_it = row_it->begin(); value_it != row_it->end(); ++value_it)
        {
            cout << *value_it << "   " << "\t";
        }
        cout << endl;
    }
}