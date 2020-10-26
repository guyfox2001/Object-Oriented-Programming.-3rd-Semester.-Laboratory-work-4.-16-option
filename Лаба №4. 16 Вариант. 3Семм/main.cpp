#include <iostream>
#include "Matrix.h"
#include"ComplexNumber.h"
using namespace std;

int main(int argc, char * argv[]) {
	Matrix<ComplexNumber> object(3,3), object1(3,3);
	object = object1;

	cin >> object;
	cout << object;
}