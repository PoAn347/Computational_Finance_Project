// TestOptionPrice.cpp
//
//

#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include "EuropeanOption.hpp"
#include "OptionArrayPrice.hpp"

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	long N = 40;

	// Create abscissa x array
	double A = 10.0;  double B = 50.0;
	auto x = CreateMesh(N, A, B);

	PlainOption myOption1(.25, 25, .3, .08, 20, .08);//Batch: T = 0.25, K = 25, sig = 0.30, r = 0.08, S = 20 

	OptionArrayPrice opa1(myOption1);

	opa1.generateOptionArrays(x);
	opa1.printCallOptionArray();
	vector<double> vecCall = opa1.getCallOptionArray();
	vector<double> vecPut = opa1.getPutOptionArray();

	//auto fun = [](double x) { return x * x; };
	//auto vec1 = CreateDiscreteFunction< std::vector<double>>(x, fun);

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, vecCall, "Call Price");
	xl.CreateChart(x, vecPut, "Put Price");

	// C++11 style initializer lists
	// std::list<std::string> labels{ "x^2", "x^3" };
	std::list<std::string> labels;
	labels.push_back("Call Price");
	labels.push_back("Put Price");

	// C++11 style initializer lists
	// std::list<std::vector<double>> curves{ vec1, vec2 };
	std::list<std::vector<double>> curves;
	curves.push_back(vecCall);
	curves.push_back(vecPut);

	xl.CreateChart(x, labels, curves, "Call & Put", "H", "V");

	return 0;
}