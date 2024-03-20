#ifndef OPTION_HPP
#define OPTION_HPP

#include <iostream>
#include <string>

class Option {
protected:
    double T; // Expiry time/maturity
    double K; // Strike price
    double sig; // Volatility
    double r; // Risk-free interest rate
    double S; // Current stock price
    double b; // Cost of carry, default to r

public:
    // Constructors
    Option();
    Option(double T, double K, double sig, double r, double S, double b = 0.0);

    // Copy constructor
    Option(const Option& other);

    // Destructor
    virtual ~Option();

    // Assignment operator
    Option& operator=(const Option& other);

    // Getter and setter functions
    double getT() const;
    void setT(double T);
    double getK() const;
    void setK(double K);
    double getSig() const;
    void setSig(double sig);
    double getR() const;
    void setR(double r);
    double getS() const;
    void setS(double S);
    double getB() const;
    void setB(double b);

    // Virtual functions to be overridden by derived classes
    virtual double CallPrice() const = 0;
    virtual double PutPrice() const = 0;

};

#endif // OPTION_HPP