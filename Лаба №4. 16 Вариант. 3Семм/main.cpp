#include <iostream>
#include "Matrix.h"
#include "ComplexNumber.h"
#include "IntervalNumber.h"
using namespace std;

/*
* TO DO: Причесать мейн
*/

int main(int argc, char * argv[]) {
	Matrix< ComplexNumber > CompMatrixA(3,3), CompMatrixB(3, 3), CompMatrixC;
	Matrix <IntervalNumber> IntervalMatrixA(3, 3), IntervalMatrixB(3, 3), IntervalMatrixC;

	cout << "Now the matrix A of complex numbers will be introduced \n";
	/*cin >> CompMatrixA;*/
	CompMatrixA.rand_value();
	cout << endl << CompMatrixA;
	cout << "Now the matrix B of complex numbers will be introduced \n";
	/*cin >> CompMatrixB;*/
	CompMatrixB.rand_value();
	cout << endl << CompMatrixB;



	CompMatrixC = CompMatrixA - CompMatrixB;
	cout << endl << CompMatrixC;


	
}