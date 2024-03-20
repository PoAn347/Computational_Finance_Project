#include "DividedDifferences.hpp"
#include "EuropeanOption.hpp"

// Constructor with PlainOption
DividedDifferences::DividedDifferences(const PlainOption& opt)
{
    my_option = opt;
}

// Destructor
DividedDifferences::~DividedDifferences() {}

// Calculate delta using divided differences for a given h
void DividedDifferences::CalculateCallDeltaByDividedDifferences(double h)
{
    double S_plus_h = my_option.Stock() + h;
    double S_minus_h = my_option.Stock() - h;
    double S_original = my_option.Stock();

    // Calculate option prices at S + h and S - h
    my_option.Stock(S_plus_h);

    double C_plus_h = my_option.GetCallPrice();

    my_option.Stock(S_minus_h);
    double C_minus_h = my_option.GetCallPrice();

    // Reset the stock price to its original value
    my_option.Stock(S_original);
    
    // Calculate delta using divided differences
    my_call_delta = (C_plus_h - C_minus_h) / (2 * h);
}

// Calculate delta using divided differences for a given h
void DividedDifferences::CalculatePutDeltaByDividedDifferences(double h)
{
    double S_plus_h = my_option.Stock() + h;
    double S_minus_h = my_option.Stock() - h;
    double S_original = my_option.Stock();

    // Calculate option prices at S + h and S - h
    my_option.Stock(S_plus_h);
    double P_plus_h = my_option.GetPutPrice();

    my_option.Stock(S_minus_h);
    double P_minus_h = my_option.GetPutPrice();

    // Reset the stock price to its original value
    my_option.Stock(S_original);

    // Calculate delta using divided differences
    my_put_delta = (P_plus_h - P_minus_h) / (2 * h);
}

// Calculate gamma using divided differences for a given h
void DividedDifferences::CalculateGammaByDividedDifferences(double h)
{
    double S_plus_h = my_option.Stock() + h;
    double S_minus_h = my_option.Stock() - h;
    double S_original = my_option.Stock();

    // Calculate option prices at S + h, S, and S - h
    my_option.Stock(S_plus_h);
    double C_plus_h = my_option.GetCallPrice();

    my_option.Stock(S_original);
    double C = my_option.GetCallPrice();

    my_option.Stock(S_minus_h);
    double C_minus_h = my_option.GetCallPrice();

    // Reset the stock price to its original value
    my_option.Stock(S_original);

    // Calculate gamma using divided differences
    my_gamma = (C_plus_h - 2 * C + C_minus_h) / (h * h);
}

double DividedDifferences::GetCallDelta() const
{
    return my_call_delta;
}

double DividedDifferences::GetPutDelta() const
{
    return my_put_delta;
}

double DividedDifferences::GetGamma() const
{
    return my_gamma;
}