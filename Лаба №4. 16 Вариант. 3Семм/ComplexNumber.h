#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
class ComplexNumber
{
public:
	ComplexNumber();
	ComplexNumber(double Rm, double Im);
	double& get_Rm();
	double& get_Im();
	void set_Rm(double Rm);
	void set_Im(double Im);
	void rand_value();
	friend std::ostream& operator<<(std::ostream& OurStream, ComplexNumber& OurObj);
	friend std::istream& operator>>(std::istream& OurStream, ComplexNumber& OurObj);
	friend ComplexNumber& operator-(ComplexNumber& Left, ComplexNumber& Right);
	ComplexNumber& operator=(ComplexNumber& Right);

private:
	double Real;
	double Imaginary—oefficient;
	std::string MathematicalNotation;

	void update_MathematicalNotation();
};
#endif // !COMPLEXNUMBER_H


