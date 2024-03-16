/*
A. Exact Solutions of One-Factor Plain Options
Part A
Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13337, P = 5.84628).
Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96557, P = 7.96557).
Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204058, P = 4.07326).
Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.17570, P = 1.24750).

a) Implement the above formulae for call and put option pricing using the data sets Batch 1 to Batch 4. Check
your answers, as you will need them when we discuss numerical methods for option pricing.
b) Apply the put-call parity relationship to compute call and put option prices. For example, given the call price,
compute the put price based on this formula using Batches 1 to 4. Check your answers with the prices from
part a). Note that there are two useful ways to implement parity: As a mechanism to calculate the call (or put)
price for a corresponding put (or call) price, or as a mechanism to check if a given set of put/call prices
satisfy parity. The ideal submission will neatly implement both approaches.
c) Say we wish to compute option prices for a monotonically increasing range of underlying values of S, for
example 10, 11, 12, …, 50. To this end, the output will be a vector. This entails calling the option pricing
formulae for each value S and each computed option price will be stored in a std::vector<double>
object. It will be useful to write a global function that produces a mesh array of doubles separated by a mesh
size h.
d) Now we wish to extend part c and compute option prices as a function of i) expiry time, ii) volatility, or iii)
any of the option pricing parameters. Essentially, the purpose here is to be able to input a matrix (vector of
vectors) of option parameters and receive a matrix of option prices as the result. Encapsulate this
functionality in the most flexible/robust way you can think of.

Option Sensitivities, aka the Greeks
Part B
a) Implement the above formulae for gamma for call and put future option pricing using the data set: K = 100,
S = 105, T = 0.5, r = 0.1, b = 0 and sig = 0.36. (exact delta call = 0.5946, delta put = -0.3566).
b) We now use the code in part a to compute call delta price for a monotonically increasing range of
underlying values of S, for example 10, 11, 12, …, 50. To this end, the output will be a vector and it entails
calling the above formula for a call delta for each value S and each computed option price will be store in a
std::vector<double> object. It will be useful to reuse the above global function that produces a mesh
array of double separated by a mesh size h.
4
c) Incorporate this into your above matrix pricer code, so you can input a matrix of option parameters and receive
a matrix of either Delta or Gamma as the result.
d) We now use divided differences to approximate option sensitivities. In some cases, an exact formula may not
exist (or is difficult to find) and we resort to numerical methods. In general, we can approximate first and
second-order derivatives in S by 3-point second order approximations, for example:
In this case the parameter h is ‘small’ in some sense. By Taylor’s expansion you can show that the above
approximations are second order accurate in h to the corresponding derivatives.
The objective of this part is to perform the same calculations as in parts a and b, but now using divided
differences. Compare the accuracy with various values of the parameter h (In general, smaller values of h
produce better approximations but we need to avoid round-offer errors and subtraction of quantities that are
very close to each other). Incorporate this into your well-designed class structure.
*/

/* 
The "EuropeanOption" file comprises the "PlainOption" class, which encapsulates various variables and functions pertaining to options and Greeks. 
It includes getter and setter functions for the option's variables and characteristics. 
Additionally, the class features a "Put-Call Parity" function for calculating the corresponding option price and verifying put-call parity.

The "OptionArrayBase" serves as the base class with two derived classes: "OptionArrayPrice" and "OptionArrayDelta." 
This class includes protected variables and an pure virtual function, "generateOptionArray," 
which can be implemented in the derived classes to produce corresponding data arrays. 
The results are stored in protected variables such as "callOptionArray."

Similar to "OptionArrayBase," "OptionMatrixBase" is the base class for "OptionMatrixPrice," "OptionMatrixDelta," and "OptionMatrixGamma." 
It includes an pure virtual function used by its derived classes. 
The "generatingOptionMatrices" function takes a pair of strings as its first argument and a matrix of pairs of doubles as its second argument. 
The output is a double matrix with the same number of rows and columns.

The "Mesh" header files contain functions to generate mesh arrays and mesh matrices. 
The "DividedDifferences" files introduce the "DividedDifferences" class, which has the "PlainOption" class as one of its private variables. 
It includes functions for calculating prices and getter functions to retrieve data.

*/ 


#include "EuropeanOption.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include "Mesh.hpp"

#include "OptionArrayBase.hpp"
#include "OptionArrayPrice.hpp"
#include "OptionArrayDelta.hpp"

#include "OptionMatrixBase.hpp"
#include "OptionMatrixPrice.hpp"
#include "OptionMatrixDelta.hpp"
#include "OptionMatrixGamma.hpp"

#include "DividedDifferences.hpp"

int main()
{	
	//Part A
	//a
	cout << "Part A - a" << endl;

	//Create 4 Batches of plain option
	PlainOption myOption1(0.25, 65.0, 0.30, 0.08, 60.0, 0.08);
	PlainOption myOption2(1.00, 100.0, 0.20, 0.00, 100.0, 0.00);
	PlainOption myOption3(1.00, 10.0, 0.50, 0.12, 5.0, 0.12);
	PlainOption myOption4(30.00, 100.0, 0.30, 0.08, 100.0, 0.08);

	cout << "\n" << endl;
	
	//b
	cout << "Part A - b" << endl;

	//Test Put-Call Parity and computes the corresponding call option price for myOption1.
	cout << myOption1.CorrespondingOptionPrice("P", 5.84628) << endl;
	cout << "Put-call Parity result is (0 = False, 1 = True): " <<  myOption1.checkPutCallParity() << endl;

	cout << "\n" << endl;

	//c
	cout << "Part A - c" << endl;

	//Using generateMesh function to create stock price array from 10 to 50
	vector<double> stockPriceArrays = generateMesh(10, 50, 1);

	//Print out each stock price
	printArray(stockPriceArrays);
	
	//Create OptionArrayPrice object with the given PlainOption myOption3
	OptionArrayPrice oap1(myOption3);

	//Generate call and put option price arrays based on the stock price array
	cout << "Stock Price:" << endl;
	oap1.generateOptionArrays(stockPriceArrays);
	cout << endl;

	//Print the generated call option price array
	cout << "Call Price Array:" << endl;
	oap1.printCallOptionArray();
	cout << endl;

	//Print the generated put option price array
	cout << "Put Price Array:" << endl;
	oap1.printPutOptionArray();

	cout << "\n" << endl;
	
	//d
	cout << "Part A - d" << endl;

	//Generate a matrix with varying stock prices and time
	// generateMatrixMesh( rowStart, rowEnd, rowStep, colStart, colEnd, colStep )
	//Parameters:
	// - rowStart, rowEnd, rowStep: Define the range and step size for stock prices.
	// - colStart, colEnd, colStep: Define the range and step size for expiry time
	//Returns:
	// A 2D matrix where each element is a pair of stock and expiry time.
	vector<vector<pair<double, double>>> StockTimeMatrix = generateMatrixMesh(10, 50, 1, 0.5, 2.5, 0.5);
	
	// Function to print out the mesh matrix
	cout << "Stock-Time Matrix:" << endl;
	printMatrix(StockTimeMatrix);
	
	OptionMatrixPrice omp1(myOption3);

	//Generate option matrices for varying stock price and expiry time.
	//Parameters:
	//  - make_pair("Stock", "Time"): Indicate that the first element of each pair in StockTimeMatrix corresponds to stock prices, and the second element correspond to expiry time.
	//  - StockTimeMatrix: A matrix containing pairs of stock and time, where each row represents a different stock price, and each column represents a different expiry time.
	omp1.generatingOptionMatrices(make_pair("Stock","Time"), StockTimeMatrix);

	cout << "Row: Stock Price ( 10 ~ 50 ; 1 ), Column: Time ( 0.5 ~ 2.5 ; 0.5 )" << endl;
	cout << "Call price matrix" << endl;
	omp1.printCallOptionMatrix();
	cout << "Put price matrix" << endl;
	omp1.printPutOptionMatrix();
	
	// A 2D matrix where each element is a pair of stock and volatility.
	vector<vector<pair<double, double>>> StockSigmaMatrix = generateMatrixMesh(10, 20, 1, 0.3, 0.5, 0.05);
	
	//Generate a matrix with varying stock prices and volatility
	omp1.generatingOptionMatrices(make_pair("Stock","Volatility"), StockSigmaMatrix);

	
	cout << "Row: Stock Price ( 10 ~ 50 ; 1 ), Column: Sigma ( 0.3 ~ 0.5 ; 0.05 )" << endl;
	cout << "Call price matrix" << endl;
	omp1.printCallOptionMatrix();
	cout << "Put price matrix" << endl;
	omp1.printPutOptionMatrix();
	

	vector<vector<pair<double, double>>> StrikeStockMatrix = generateMatrixMesh(90, 110, 5, 90, 110, 5);
	OptionMatrixPrice omp3(myOption2);
	
	omp3.generatingOptionMatrices(make_pair("Strike","Stock"), StrikeStockMatrix);
	
	cout << "Row: Strike Price ( 90 ~ 110 ; 5 ), Column: Stock Price ( 90 ~ 110 ; 5 )" << endl;
	cout << "Call price matrix" << endl;
	omp3.printCallOptionMatrix();
	cout << "Put price matrix" << endl;
	omp3.printPutOptionMatrix();
	
	cout << "\n" << endl;
	
	//Part B
	//a.
	cout << "Part B - a" << endl;

	PlainOption myOption5(0.5, 100.0, 0.36, 0.1, 105.0, 0.0);

	//Print out delta and gamma of option
	cout << "Call Delta: " << myOption5.GetCallDelta() << endl;
	cout << "Put Delta:  " << myOption5.GetPutDelta() << endl;
	cout << "Call Gamma: " << myOption5.GetCallGamma() << endl;
	cout << "Put Gamma:  " << myOption5.GetPutGamma() << endl;

	cout << "\n" << endl;

	//b. 
	cout << "Part B - b" << endl;

	//Create OptionArrayDelta object with the given PlainOption myOption5
	OptionArrayDelta oad1(myOption5);

	//Generate call and put option delta arrays based on the stock price array
	oad1.generateOptionArrays(stockPriceArrays);

	//Print the generated call option delta array
	cout << "Call Delta Array:" << endl;
	oad1.printCallOptionArray();

	//Print the generated put option delta array
	cout << "Put Delta Array:" << endl;
	oad1.printPutOptionArray();

	cout << "\n" << endl;

	//c
	cout << "Part B - c" << endl;

	//Creating an OptionMatrixDelta object(omg1) with the given PlainOption myOption5.
	OptionMatrixDelta omd1(myOption5);

	//Generating option delta matrices based on a matrix of stock prices and time 
	omd1.generatingOptionMatrices(make_pair("Stock", "Time"), StockTimeMatrix);

	
	cout << "Row: Stock Price ( 10 ~ 50 ; 1 ), Column: Time ( 0.5 ~ 2.5 ; 0.5 )" << endl;
	cout << "Call delta matrix" << endl;
	omd1.printCallOptionMatrix();
	cout << "Put delta matrix" << endl;
	omd1.printPutOptionMatrix();

	//Creating an OptionMatrixGamma object with the given PlainOption myOption5.
	OptionMatrixGamma omg1(myOption5);

	//Generating option gamma matrices based on a matrix of stock prices and time
	omg1.generatingOptionMatrices(make_pair("Stock", "Time"), StockTimeMatrix);

	
	cout << "Row: Stock Price ( 10 ~ 50 ; 1 ), Column: Time ( 0.5 ~ 2.5 ; 0.5 )" << endl;
	cout << "Call gamma matrix" << endl;
	omg1.printCallOptionMatrix();

	cout << "Put gamma matrix" << endl;
	omg1.printPutOptionMatrix();
	
	cout << "\n" << endl;

	//d
	cout << "Part B - d" << endl;

	//For a question
	//Creating a DividedDifferences object  with the given PlainOption myOption5
	DividedDifferences dd(myOption5);

	//cout << myOption1.GetCallDelta() << endl;

	// Calculating call delta, put delta, and gamma 
	dd.CalculateCallDeltaByDividedDifferences(0.1);
	dd.CalculatePutDeltaByDividedDifferences(0.1);
	dd.CalculateGammaByDividedDifferences(0.1);

	//Printing the calculated call delta, put delta, and gamma
	cout << "Call Delta: " << dd.GetCallDelta() << endl;
	cout << "Put  Delta: " << dd.GetPutDelta() << endl;
	cout << "Call Gamma: " << dd.GetGamma() << endl;
	
	//For b question
	//Generating option sensitivities with different h values and comparing the estimates with exact values.
	
	//Using generateMesh to create an array of h values.
	vector<double> hArrays = generateMesh(.1, 5.1, .5);
	
	//Calculating call delta, put delta, and gamma for each h value
	//Printing the h value, estimated sensitivities, and the difference between the exact and estimated values.
	cout << endl;
	cout << "Divided Difference with different h value for call delta" << endl;

	for (auto it = hArrays.begin(); it != hArrays.end(); it++)
	{
		dd.CalculateCallDeltaByDividedDifferences(*it);
		cout << "h value: " << *it << endl;
		cout << "Estimated Call Delta: " << dd.GetCallDelta() << endl;
		cout << "Exact - Estimate:  " << myOption5.GetCallDelta() - dd.GetCallDelta() << endl;
	}

	cout << endl;
	cout << "Divided Difference with different h value for put delta" << endl;

	for (auto it = hArrays.begin(); it != hArrays.end(); it++)
	{
		dd.CalculatePutDeltaByDividedDifferences(*it);
		cout << "h value: " << *it << endl;
		cout << "Estimated Put Delta: " << dd.GetPutDelta() << endl;
		cout << "Exact - Estimate:  " << myOption5.GetPutDelta() - dd.GetPutDelta() << endl;
	}

	cout << endl;
	cout << "Divided Difference with different h value for gamma" << endl;

	for (auto it = hArrays.begin(); it != hArrays.end(); it++)
	{
		dd.CalculateGammaByDividedDifferences(*it);
		cout << "h value: " << *it << endl;
		cout << "Estimated Gamma: " << dd.GetGamma() << endl;
		cout << "Exact - Estimate:  " << myOption5.GetCallGamma() - dd.GetGamma() << endl;
	}

	cout << "\n" << endl;

	return 0;
}
