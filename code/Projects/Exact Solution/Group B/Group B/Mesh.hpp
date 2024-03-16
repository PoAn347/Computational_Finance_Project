#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
using namespace std;


//For stock price array
vector<double> generateMesh(double start, double end, double step)
{
	vector<double> mesh;

	for (double value = start; value <= end; value += step)
	{
		mesh.push_back(value);
	}

	return mesh;
}

// Function to generate a matrix of mesh
vector<vector<pair<double, double>>> generateMatrixMesh(double startRow, double endRow, double stepRow,
    double startCol, double endCol, double stepCol)
{
    vector<vector<pair<double, double>>> mesh;

    for (double rowValue = startRow; rowValue <= endRow; rowValue += stepRow)
    {
        vector<pair<double, double>> rowMesh;

        for (double colValue = startCol; colValue <= endCol; colValue += stepCol)
        {
            rowMesh.push_back(make_pair(rowValue,colValue));
        }

        mesh.push_back(rowMesh);
    }

    return mesh;
}

//Print out each stock price
void printArray(const vector<double>& stockPriceArrays)
{
    for (auto it = stockPriceArrays.begin(); it != stockPriceArrays.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


// Function to print out the matrix using iterators
void printMatrix(const vector<vector<pair<double, double>>>& matrix)
{
    for (auto row_it = matrix.begin(); row_it != matrix.end(); ++row_it)
    {
        for (auto element_it = row_it->begin(); element_it != row_it->end(); ++element_it)
        {
            std::cout << "(" << element_it->first << ", " << element_it->second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif