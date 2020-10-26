#include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
	this->Real = 0;
	this->Imaginary—oefficient = 0;
	this->MathematicalNotation = "";
}

ComplexNumber::ComplexNumber(double Rm, double Im)
{
	this->Real = Rm;
	this->Imaginary—oefficient = Im;
	this->update_MathematicalNotation();
}

double& ComplexNumber::get_Rm()
{
	return this->Real;
}

double& ComplexNumber::get_Im()
{
	return this->Imaginary—oefficient;
}

void ComplexNumber::set_Rm(double Rm)
{
	this->Real = Rm;
}

void ComplexNumber::set_Im(double Im)
{
	this->Imaginary—oefficient = Im;
}

ComplexNumber& ComplexNumber::operator=(ComplexNumber& Right)
{
	this->Imaginary—oefficient = Right.Imaginary—oefficient;
	this->Real = Right.Real;
	this->MathematicalNotation = Right.MathematicalNotation;
	return *this;
}

void ComplexNumber::update_MathematicalNotation()
{
	this->MathematicalNotation = std::to_string(this->Real) + ' ' + '+' + std::to_string(this->Imaginary—oefficient) + 'i';
}

std::ostream& operator<<(std::ostream& OurStream, ComplexNumber& OurObj)
{
	try {
		if (OurObj.MathematicalNotation.empty())throw "0";
		OurStream << OurObj.MathematicalNotation;
	}
	catch (const char* ExceptionString) {
		OurStream << ExceptionString;
	}
	return OurStream;
}

std::istream& operator>>(std::istream& OurStream, ComplexNumber& OurObj)
{
	std::cout << "Please input Real: ";
	OurStream >> OurObj.Real;
	std::cout << "Please input Imaginary—oefficient: ";
	OurStream >> OurObj.Imaginary—oefficient;
	OurObj.update_MathematicalNotation();
	return OurStream;
}

ComplexNumber& operator-(ComplexNumber& Left, ComplexNumber& Right)
{
	static ComplexNumber Result;
	Result.set_Im(Left.get_Im() - Right.get_Im());
	Result.set_Rm(Left.get_Rm() - Right.get_Rm());
	return Result;
}
