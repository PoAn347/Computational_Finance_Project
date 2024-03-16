#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP


#include <iostream>
using namespace std;


class PlainOption
{
private:
	//Private member variables
	double T; //T (expiry time/maturity).
	double K;//K (strike price)
	double sig; //sig (volatility).
	double r;//r(risk - free interest rate).
	double S;//S(current stock price where we wish to price the option).
	double b;		// Cost of carry Defaut to r

	double C = CallPrice();//C = call option price 
	double P = PutPrice();//P = put option price

	
	double C_Delta = CallDelta();
	double P_Delta = PutDelta();
	double C_Gamma = CallGamma();
	double P_Gamma = PutGamma();
	double C_Vega = CallVega();
	double P_Vega = PutVega();
	double C_Theta = CallTheta();
	double P_Theta = PutTheta();
	

	//string optType;

	//Private helper function for d1, d2
	double calculateD1() const;
	double calculateD2() const;

	//Functions
	//Calculate Call price
	double CallPrice() const;

	//Calculate Put price
	double PutPrice() const;

	//Calculate Option's Delta
	double CallDelta() const;

	double PutDelta() const;

	//Calculate Option's Gamma
	double CallGamma() const;

	double PutGamma() const;

	//Calculate Option's Vega
	double CallVega() const;

	double PutVega() const;

	//Calculate Option's Theta
	double CallTheta() const;

	double PutTheta() const;

public:
	//Default Constructor
	PlainOption();

	//Constructor with given value
	PlainOption(double T, double K, double sig, double r, double S, double b );
	
	//copy constructor
	PlainOption(const PlainOption& o2);

	//Destructor
	virtual ~PlainOption();

	//Assignment operator
	PlainOption& operator = (const PlainOption& source);

	//Getter and Setter function for the underlying asset price
	void Stock(double new_S);
	double Stock() const;

	//Getter and Setter function for the expiry time
	void Time(double new_T);
	double Time() const;

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

	//Get function
	double GetCallDelta() const;
	double GetPutDelta() const;

	//Get function
	double GetCallGamma() const;
	double GetPutGamma() const;

	//Put-Call Parity
	double CorrespondingOptionPrice(string opt, double otherOptionPrice) const;

	// New member function for checking put-call parity
	bool checkPutCallParity() const;


};

#endif 