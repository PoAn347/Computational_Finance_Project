#include "NormalFunction.hpp"
#include "AmericanOption.hpp"
#include <iostream>
#include <cmath>

//Private helper function for d1, d2
double PerpetualAmericanOption::calculateY1() const
{
	double tmp = (b/(sig*sig) - 0.5) * (b / (sig * sig) - 0.5) + (2 * r) / (sig * sig);

	double y1 = 0.5 - b / (sig*sig) + sqrt(tmp);

	return y1;
}
double PerpetualAmericanOption::calculateY2() const
{
	double tmp = (b / (sig * sig) - 0.5) * (b / (sig * sig) - 0.5) + (2 * r) / (sig * sig);
	
	double y2 = 0.5 - b / (sig * sig) - sqrt(tmp);

	return y2;
}
	
//Calculate Call price
double PerpetualAmericanOption::CallPrice() const
{	
	double y1 = calculateY1();

	return K / (y1 - 1) * pow(( (y1-1) / y1 * (S / K) ), y1);
}

//Calculate Put price
double PerpetualAmericanOption::PutPrice() const
{
	double y2 = calculateY2();

	return K / (1 - y2) * pow(((y2 - 1) / y2 * (S / K)), y2);
}

//Default Constructor
PerpetualAmericanOption::PerpetualAmericanOption() : Option(0, 100.0, 0.1, 0.1, 110.0, 0.02)
{

}

//Constructor with given value
PerpetualAmericanOption::PerpetualAmericanOption(double K, double sig, double r, double S, double b ): Option(0, K, sig, r, S, b)
{
	//cout << "Given value constructor of PlainOption" << endl;
	cout << "Call Option Price: " << C << endl;
	cout << "Put Option Price: " << P << endl;
}

//copy constructor
PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& o2) : Option(o2)
{
	
}

//Destructor
PerpetualAmericanOption::~PerpetualAmericanOption()
{

}

//Assignment operator
PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source)
{
	if (this == &source) return *this;

	Option::operator=(source);
	
	return *this;
}

// Setter and Getter function for the underlying asset price
void PerpetualAmericanOption::Stock(double newS)
{
	S = newS;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
}

double PerpetualAmericanOption::Stock() const
{
	return S;
}


//Getter and Setter function for the Volatility
void PerpetualAmericanOption::Volatility(double new_sig)
{
	sig = new_sig;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
}

double PerpetualAmericanOption::Volatility() const
{
	return sig;
}

//Getter and Setter function for the strike price
void PerpetualAmericanOption::Strike(double new_K)
{
	K = new_K;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
}

double PerpetualAmericanOption::Strike() const
{
	return K;
}

//Getter and Setter function for the risk-free rate
void PerpetualAmericanOption::RiskFree(double new_r)
{
	r = new_r;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
}

double PerpetualAmericanOption::RiskFree() const
{
	return r;
}

//Getter and Setter function for the risk-free rate
void PerpetualAmericanOption::CarryCost(double new_b)
{
	b = new_b;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
}

double PerpetualAmericanOption::CarryCost() const
{
	return b;
}

double PerpetualAmericanOption::GetCallPrice() const
{
	return C;
}

double PerpetualAmericanOption::GetPutPrice() const
{
	return P;
}


