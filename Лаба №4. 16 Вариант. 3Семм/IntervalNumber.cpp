#include "IntervalNumber.h"

IntervalNumber::IntervalNumber()
{
	this->LeftNumber = 0;
	this->RightNumber = 0;
	this->MathematicalNotation = "[0; 0]";
}

IntervalNumber::IntervalNumber(double LeftNumber, double RightNumber)
{
	this->LeftNumber = RightNumber;
	this->RightNumber = LeftNumber;
	this->update_MathematicalNotation();
}

double& IntervalNumber::get_LeftNumber()
{
	return this->LeftNumber;
}

double& IntervalNumber::get_RightNumber()
{
	return this->RightNumber;
}

void IntervalNumber::set_LeftNumber(double LeftNumber)
{
	this->LeftNumber = LeftNumber;
	this->update_MathematicalNotation();

}

void IntervalNumber::set_RightNumber(double RightNumber)
{
	this->RightNumber = RightNumber;
	this->update_MathematicalNotation();
}

IntervalNumber& IntervalNumber::operator=(IntervalNumber& Right)
{
	this->LeftNumber = Right.LeftNumber;
	this->RightNumber = Right.RightNumber;
	this->MathematicalNotation = Right.MathematicalNotation;
	return *this;
}

void IntervalNumber::update_MathematicalNotation()
{
	this->MathematicalNotation = '[' + std::to_string(this->LeftNumber) + ';' + std::to_string(this->RightNumber) + ']';
}

std::ostream& operator<<(std::ostream& OurStream, IntervalNumber& OurObj)
{
	OurStream << OurObj.MathematicalNotation;
	return OurStream;
}

std::istream& operator>>(std::istream& OurStream, IntervalNumber& OurObj)
{
	std::cout << "Please input Left Number\n";
	OurStream >> OurObj.LeftNumber;
	std::cout << "Please input Right Number\n";
	OurStream >> OurObj.RightNumber;
	return OurStream;
}

IntervalNumber& operator-(IntervalNumber& Left, IntervalNumber& Right)
{
	static IntervalNumber Result;
	Result.set_LeftNumber(Left.get_LeftNumber() - Right.get_LeftNumber());
	Result.set_RightNumber(Left.get_RightNumber() - Right.get_RightNumber());
	Result.update_MathematicalNotation();
	return Result;
}
