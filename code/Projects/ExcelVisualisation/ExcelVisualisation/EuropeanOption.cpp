#include "NormalFunction.hpp"
#include "EuropeanOption.hpp"
#include <iostream>
#include <cmath>

//Private helper function for d1, d2
double PlainOption::calculateD1() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;

	return d1;
}
double PlainOption::calculateD2() const
{
	double tmp = sig * sqrt(T);

	double d1 = calculateD1();
	double d2 = d1 - tmp;

	return d2;
}
	
//Calculate Call price
double PlainOption::CallPrice() const
{	
	double d1 = calculateD1();
	double d2 = calculateD2();

	return (S * exp((b - r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));
}

//Calculate Put price
double PlainOption::PutPrice() const
{
	double d1 = calculateD1();
	double d2 = calculateD2();

	return (K * exp(-r * T) * N(-d2)) - (S * exp((b - r) * T) * N(-d1));
}

//Calculate Option's Delta
double PlainOption::CallDelta() const
{
	double d1 = calculateD1();

	return exp((b - r) * T) * N(d1);
}

double PlainOption::PutDelta() const
{

	double d1 = calculateD1();

	return exp((b - r) * T) * (N(d1) - 1.0);
}

//Calculate Option's Gamma
double PlainOption::CallGamma() const
{

	double tmp = sig * sqrt(T);
	
	double d1 = calculateD1();
	double d2 = calculateD2();

	return (n(d1) * exp((b - r) * T)) / (S * tmp);
}
double PlainOption::PutGamma() const
{
	return CallGamma();
}

//Calculate Option's Vega
double PlainOption::CallVega() const
{

	double d1 = calculateD1();

	return (S * exp((b - r) * T) * n(d1) * sqrt(T));
}

double PlainOption::PutVega() const
{
	return CallVega();
}

//Calculate Option's Theta
double PlainOption::CallTheta() const
{

	double d1 = calculateD1();
	double d2 = calculateD2();

	double t1 = (S * exp((b - r) * T) * n(d1) * sig * 0.5) / sqrt(T);
	double t2 = (b - r) * (S * exp((b - r) * T) * N(d1));
	double t3 = r * K * exp(-r * T) * N(d2);

	return -(t1 + t2 + t3);
}

double PlainOption::PutTheta() const
{

	double d1 = calculateD1();
	double d2 = calculateD2();

	double t1 = (S * exp((b - r) * T) * n(d1) * sig * 0.5) / sqrt(T);
	double t2 = (b - r) * (S * exp((b - r) * T) * N(-d1));
	double t3 = r * K * exp(-r * T) * N(-d2);

	return t2 + t3 - t1;
}

//Default Constructor
PlainOption::PlainOption(): T(1.0), K(10.0), sig(0.5), r(0.12), S(5.0), b(0.12)
{
	//cout << "Default constructor of PlainOption" << endl;
	//cout << "Call Option Price: " << C << endl;
	//cout << "Put Option Price: " << P << endl;
}

//Constructor with given value
PlainOption::PlainOption(double T, double K, double sig, double r, double S, double b ): T(T), K(K), sig(sig), r(r), S(S), b(b)
{
	//cout << "Given value constructor of PlainOption" << endl;
	cout << "Call Option Price: " << C << endl;
	cout << "Put Option Price: " << P << endl;
}

//copy constructor
PlainOption::PlainOption(const PlainOption& o2)
{
	//cout << "Copy constructor of PlainOption" << endl;
	T = o2.T;
	//cout << T << endl;
	K = o2.K;
	//cout << K << endl;
	sig = o2.sig;
	//cout << sig << endl;
	r = o2.r;
	S = o2.S;
	b = o2.b;
}

//Destructor
PlainOption::~PlainOption()
{

}

//Assignment operator
PlainOption& PlainOption::operator = (const PlainOption& source)
{
	if (this == &source) return *this;

	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	S = source.S;
	b = source.b;
	
	return *this;
}

// Setter and Getter function for the underlying asset price
void PlainOption::Stock(double newS)
{
	S = newS;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
	C_Delta = CallDelta();
	P_Delta = PutDelta();
	C_Gamma = CallGamma();
	P_Gamma = PutGamma();
	C_Vega = CallVega();
	P_Vega = PutVega();
	C_Theta = CallTheta();
	P_Theta = PutTheta();
}

double PlainOption::Stock() const
{
	return S;
}

// Setter and Getter function for the expiry time
void PlainOption::Time(double newT)
{
	T = newT;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
	C_Delta = CallDelta();
	P_Delta = PutDelta();
	C_Gamma = CallGamma();
	P_Gamma = PutGamma();
	C_Vega = CallVega();
	P_Vega = PutVega();
	C_Theta = CallTheta();
	P_Theta = PutTheta();
}

double PlainOption::Time() const
{
	return T;
}

//Getter and Setter function for the Volatility
void PlainOption::Volatility(double new_sig)
{
	sig = new_sig;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
	C_Delta = CallDelta();
	P_Delta = PutDelta();
	C_Gamma = CallGamma();
	P_Gamma = PutGamma();
	C_Vega = CallVega();
	P_Vega = PutVega();
	C_Theta = CallTheta();
	P_Theta = PutTheta();
}

double PlainOption::Volatility() const
{
	return sig;
}

//Getter and Setter function for the strike price
void PlainOption::Strike(double new_K)
{
	K = new_K;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
	C_Delta = CallDelta();
	P_Delta = PutDelta();
	C_Gamma = CallGamma();
	P_Gamma = PutGamma();
	C_Vega = CallVega();
	P_Vega = PutVega();
	C_Theta = CallTheta();
	P_Theta = PutTheta();
}

double PlainOption::Strike() const
{
	return K;
}

//Getter and Setter function for the risk-free rate
void PlainOption::RiskFree(double new_r)
{
	r = new_r;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
	C_Delta = CallDelta();
	P_Delta = PutDelta();
	C_Gamma = CallGamma();
	P_Gamma = PutGamma();
	C_Vega = CallVega();
	P_Vega = PutVega();
	C_Theta = CallTheta();
	P_Theta = PutTheta();
}

double PlainOption::RiskFree() const
{
	return r;
}

//Getter and Setter function for the risk-free rate
void PlainOption::CarryCost(double new_b)
{
	b = new_b;

	//Need to update the Call and Put Price and other greeks
	C = CallPrice();
	P = PutPrice();
	C_Delta = CallDelta();
	P_Delta = PutDelta();
	C_Gamma = CallGamma();
	P_Gamma = PutGamma();
	C_Vega = CallVega();
	P_Vega = PutVega();
	C_Theta = CallTheta();
	P_Theta = PutTheta();
}

double PlainOption::CarryCost() const
{
	return b;
}

double PlainOption::GetCallPrice() const
{
	return C;
}

double PlainOption::GetPutPrice() const
{
	return P;
}

double PlainOption::GetCallDelta() const
{
	return C_Delta;
}

double PlainOption::GetPutDelta() const
{
	return P_Delta;
}

double PlainOption::GetCallGamma() const
{
	return C_Gamma;
}

double PlainOption::GetPutGamma() const
{
	return P_Gamma;
}
//Put-Call Parity
double PlainOption::CorrespondingOptionPrice(string opt, double sourceOptionPrice) const
{

	//Calculate the corresponding option price based on put-call parity
	if(opt == "P" || "p")
	{	
		//source is put option
		return sourceOptionPrice + S - K * exp(-r * T);
	}
	else if(opt == "C" || "c")
	{
		//source is call option
		return sourceOptionPrice - S + K * exp(-r * T);
	}
	else
	{
		cout << "Please enter option type and its price. Ex.(\"C\", 12.00) " << endl;
	}
}

// New member function for checking put-call parity
bool PlainOption::checkPutCallParity() const
{	
	cout << "Call Option Price: " << C << endl;
	cout << "Put Option Price: " << P << endl;
	// Check if the given put/call prices satisfy put-call parity
	return (C - P) == (S - K * exp(-r * T));
}
