#include "OptionMatrixBase.hpp"
#include "EuropeanOption.hpp"
#include <iostream>

OptionMatrixBase::OptionMatrixBase()
{
}

OptionMatrixBase::OptionMatrixBase(const PlainOption& newOption) 
{
    my_plainOption = newOption;
}

OptionMatrixBase::OptionMatrixBase(const OptionMatrixBase& omb2) 
{
    callOptionMatrix = omb2.callOptionMatrix;
    putOptionMatrix = omb2.putOptionMatrix;
    my_plainOption = omb2.my_plainOption;
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
    my_plainOption = source.my_plainOption;

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

PlainOption OptionMatrixBase::getOptionDetails() const 
{
    return my_plainOption;
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