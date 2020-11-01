#pragma once
#include <iostream>
#include <string>
/*
* TO DO: Доделать рандом
*/
class IntervalNumber
{
public:
	IntervalNumber();
	IntervalNumber(double LeftNumber, double RightNumber);
	double& get_LeftNumber();
	double& get_RightNumber();
	void set_LeftNumber(double LeftNumber);
	void set_RightNumber(double RightNumber);
	void rand_value();
	friend std::ostream& operator<<(std::ostream& OurStream, IntervalNumber& OurObj);
	friend std::istream& operator>>(std::istream& OurStream, IntervalNumber& OurObj);
	friend IntervalNumber& operator-(IntervalNumber& Left, IntervalNumber& Right);
	IntervalNumber& operator=(IntervalNumber& Right);
private:
	double LeftNumber, RightNumber;
	std::string MathematicalNotation;

	void update_MathematicalNotation();
};

