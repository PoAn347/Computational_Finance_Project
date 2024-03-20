/*
* B. Perpetual American Options
A European option can only be exercised at the expiry date T and an exact solution is known. An American
option is a contract that can be exercised at any time prior to T. Most traded stock options are American style. In
general, there is no known exact solution to price an American option but there is one exception, namely
perpetual American options. The formulae are:
for put options.
In general, the perpetual price is the time-homogeneous price and is the same as the normal price when the
expiry price T tends to infinity. In general, American options are worth more than European options.
Answer the following questions:
a) Program the above formulae, and incorporate into your well-designed options pricing classes.
b) Test the data with K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106).
c) We now use the code in part a) to compute call and put option price for a monotonically increasing range of
underlying values of S, for example 10, 11, 12, …, 50. To this end, the output will be a vector and this
exercise entails calling the option pricing formulae in part a) for each value S and each computed option
price will be stored in a std::vector<double> object. It will be useful to reuse the above global
function that produces a mesh array of double separated by a mesh size h.
d) Incorporate this into your above matrix pricer code,so you can input a matrix of option parameters and 
receive a matrix of Perpetual American option prices
*/

/*
The "AmericanOption" file comprises the "PerpetualAmericanOption" class, encapsulating various variables and functions of the option. 
It includes getter and setter functions for the option's variables and characteristics.

The "OptionArrayBase" serves as the base class with its derived class: "OptionArrayPrice." 
This class includes protected variables and a pure virtual function, "generateOptionArray," 
which can be implemented in the derived classes to produce corresponding data arrays. 
The results are stored in protected variables such as "callOptionArray."

Similar to "OptionArrayBase," "OptionMatrixBase" is the base class for "OptionMatrixPrice." 
It includes a pure virtual function used by its derived classes. 
The "generatingOptionMatrices" function takes a pair of strings as its first argument and a matrix of pairs of doubles as its second argument. 
The output is a double matrix with the same number of rows and columns.

The "Mesh" header files contain functions to generate mesh arrays and mesh matrices.
*/

#include "AmericanOption.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include "Mesh.hpp"

#include "OptionArrayBase.hpp"
#include "OptionArrayPrice.hpp"

#include "OptionMatrixBase.hpp"
#include "OptionMatrixPrice.hpp"


int main()
{	
	//b
	cout << "Part B - b" << endl;
	//Create a perpetual american option a with K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106).
	PerpetualAmericanOption myOption1(100.0, 0.1, 0.1, 110.0, 0.02);

	cout << "\n" << endl;
	
	//c
	cout << "Part B - c" << endl;
	//Using generateMesh function to create stock price array from 10 to 50
	vector<double> stockPriceArrays = generateMesh(10, 50, 1);

	//Print out each stock price
	cout << "Stock Price Array" << endl;
	printArray(stockPriceArrays);
	cout << "\n" << endl;
	
	//Create a option price array object with given perpetual american option
	OptionArrayPrice oap1(myOption1);
	
	//Generate the option price array and put it into the call price and put price array
	oap1.generateOptionArrays(stockPriceArrays);
	
	//Print out the corresponding call and put price for ( S = 10 , 11 , .... 50 )
	cout << "Call price array" << endl;

	oap1.printCallOptionArray();
	
	cout << "\n" << endl;
	
	cout << "Put price array" << endl;

	oap1.printPutOptionArray();

	cout << "\n" << endl;
	

	//d
	cout << "Part B - d" << endl;
	//Generate a matrix with varying stock prices and strike prices
	//Parameters:
	// - rowStart, rowEnd, rowStep: Define the range and step size for stock prices.
	// - colStart, colEnd, colStep: Define the range and step size for strike prices.
	//Returns:
	// A 2D matrix where each element is a pair of stock and strike prices.
	vector<vector<pair<double, double>>> StockStrikeMatrix = generateMatrixMesh(10, 15, 1, 20, 25, 1);
	
	// Function to print out the matrix
	cout << "Stock-Strike Matrix" << endl;
	printMatrix(StockStrikeMatrix);
	
	//Create an object of OptionMatrixPricer
	OptionMatrixPrice omp1(myOption1);

	//Generate option matrices for varying stock and strike prices
	//Parameters:
	//  - make_pair("Stock", "Strike"): Indicate that the first element of each pair in StockStrikeMatrix corresponds to stock prices, and the second element correspond to strike prices.
	//  - StockStrikeMatrix: A matrix containing pairs of stock and strike prices, where each row represents a different stock price, and each column represents a different strike price.
	omp1.generatingOptionMatrices(make_pair("Stock","Strike"), StockStrikeMatrix);

	cout << "Row: Stock Price ( 10 ~ 15 ; 1 ), Column: Strike ( 20 ~ 25 ; 1 )" << endl;
	cout << "Call price matrix" << endl;
	omp1.printCallOptionMatrix();
	cout << "Put price matrix" << endl;
	omp1.printPutOptionMatrix();
	
	//Generate a matrix with varying stock prices and volitility
	vector<vector<pair<double, double>>> StockSigmaMatrix = generateMatrixMesh(10, 20, 1, 0.3, 0.5, 0.05);

	omp1.generatingOptionMatrices(make_pair("Stock","Volatility"), StockSigmaMatrix);

	cout << "Row: Stock Price ( 10 ~ 20 ; 1 ), Column: Volatility ( 0.3 ~ 0.5 ; 0.05 )" << endl;
	cout << "Call price matrix" << endl;
	omp1.printCallOptionMatrix();
	cout << "Put price matrix" << endl;
	omp1.printPutOptionMatrix();
	
	//Generate option matrices for varying strike and stock prices
	vector<vector<pair<double, double>>> StrikeStockMatrix = generateMatrixMesh(20, 25, 1, 10, 15, 1);
	
	omp1.generatingOptionMatrices(make_pair("Strike","Stock"), StrikeStockMatrix);
	
	cout << "Row: Strike ( 20 ~ 25 ; 1 ), Column: Stock Price ( 10 ~ 15 ; 1 )" << endl;
	cout << "Call price matrix" << endl;
	omp1.printCallOptionMatrix();
	cout << "Put price matrix" << endl;
	omp1.printPutOptionMatrix();

	return 0;
}
