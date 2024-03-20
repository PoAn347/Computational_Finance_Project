#ifndef DIVIDEDDIFFERENCES_HPP
#define DIVIDEDDIFFERENCES_HPP

#include "EuropeanOption.hpp"

class DividedDifferences
{
private:

    PlainOption my_option;

    double my_call_delta;
    double my_put_delta;
    double my_gamma;


public:

    DividedDifferences();

    // Constructor with PlainOption
    DividedDifferences(const PlainOption& opt);

    ~DividedDifferences();

    // Calculate delta using divided differences for a given h
    void CalculateCallDeltaByDividedDifferences(double h);

    // Calculate delta using divided differences for a given h
    void CalculatePutDeltaByDividedDifferences(double h);

    // Calculated gamma using divided differences for a given h
    void CalculateGammaByDividedDifferences(double h);

    //Get Call Delta
    double GetCallDelta() const;

    //Get Put Delta
    double GetPutDelta() const;

    //Get Gamma
    double GetGamma() const;

};

#endif