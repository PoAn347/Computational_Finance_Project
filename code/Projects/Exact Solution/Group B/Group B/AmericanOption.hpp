#ifndef AMERICANOPTION_HPP
#define AMERICANOPTION_HPP


#include <iostream>
using namespace std;


class PerpetualAmericanOption
{
private:
	//Private member variables
	double K;//K (strike price)
	double sig; //sig (volatility).
	double r;//r(risk - free interest rate).
	double S;//S(current stock price where we wish to price the option).
	double b;		// Cost of carry Defaut to r

	double C = CallPrice();//C = call option price 
	double P = PutPrice();//P = put option price
	

	//string optType;

	//Private helper function for d1, d2
	double calculateY1() const;
	double calculateY2() const;

	//Functions
	//Calculate Call price
	double CallPrice() const;

	//Calculate Put price
	double PutPrice() const;


public:
	//Default Constructor
	PerpetualAmericanOption();

	//Constructor with given value
	PerpetualAmericanOption(double K, double sig, double r, double S, double b );
	
	//copy constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& o2);

	//Destructor
	virtual ~PerpetualAmericanOption();

	//Assignment operator
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);

	//Getter and Setter function for the underlying asset price
	void Stock(double new_S);
	double Stock() const;

	//Getter and Setter function for the Volatility
	void Volatility(double new_sig);
	double Volatility() const;

	//Getter and Setter function for the strike price
	void Strike(double new_K);
	double Strike() const;

	//Getter and Setter function for the risk-free rate
	void RiskFree(double new_r);
	double RiskFree() const;

	//Getter and Setter function for the carry cost rate
	void CarryCost(double new_b);
	double CarryCost() const;

	//Get function
	double GetCallPrice() const;

	double GetPutPrice() const;


};

#endif 