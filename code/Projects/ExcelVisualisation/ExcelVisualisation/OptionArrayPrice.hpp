#ifndef OPTIONARRAYPRICE_HPP
#define OPTIONARRAYPRICE_HPP

#include <vector>
#include <iostream>
#include "EuropeanOption.hpp"  // Include the header file for PlainOption
#include "OptionArrayBase.hpp" 

using namespace std;


class OptionArrayPrice : public OptionArrayBase
{
public:
    
    //Default constructor
    OptionArrayPrice();

    //Constructor with given option
    OptionArrayPrice(const PlainOption& option);

    //copy constructor
    OptionArrayPrice(const OptionArrayPrice& oa2);

    //Destructor
    virtual ~OptionArrayPrice();

    //Assignment operator
    OptionArrayPrice& operator = (const OptionArrayPrice& source);
    
    //Computes call and put option price based on stock
    void generateOptionArrays(const vector<double>& stockarray);

    //Get function for Call Price Array
    //vector<double> CallPriceArray() const;
    
    //Get function for Call Price Array
    //vector<double> PutPriceArray() const;

    //Print out call price array
    //void PrintCallPriceArray() const;

    //Print out put price array
    //void PrintPutPriceArray() const;
};


#endif