#pragma once
#include <iostream>
#include <iomanip>
#include"ComplexNumber.h"
#include"IntervalNumber.h"
#ifndef MATRIX_H
#define MATRIX_H
/*
	� ���� �� ������� ������ � ���������� ����� friend, ����� � ���� ���� ���� ���������  
*/
template <class Template>
class Matrix
{
public:
	Matrix();
	Matrix(int rows, int colums);
	~Matrix();
	void resize(int rows, int colums);
	template<class Template>
	friend std::ostream& operator<<(std::ostream& OurStream, Matrix<Template>& OurObj);
	template<class Template>
	friend std::istream& operator>>(std::istream& OurStream, Matrix<Template>& OurObj);
	template<class Template>
	friend Matrix<Template>& operator-(Matrix<Template>& Left, Matrix<Template>& Right);
	Matrix<Template>& operator=(Matrix<Template>& Right);
	void rand_value();
private:

	Template** OurMatrix;
	int rows, colums;
};

template <class Template>
inline std::ostream& operator<<(std::ostream& OurStream,  Matrix<Template> & OurObj)
{
	try {
		if (OurObj.OurMatrix != nullptr) {
			for (int i = 0; i < OurObj.rows; i++) {
				for (int j = 0; j < OurObj.colums; j++) {
					OurStream << std::setprecision(2) << OurObj.OurMatrix[i][j] << ' ';
				}
				OurStream << '\n';
			}
		}
		else {
			throw "Matrix isn't initialazed\n";
		}
	}
	catch (const char* ExceptionString) {
		OurStream << ExceptionString;
	}
	return OurStream;
}

template <class Template>
inline std::istream& operator>>(std::istream& OurStream, Matrix<Template> & OurObj)
{
	try {
		if (OurObj.OurMatrix != nullptr) {
			for (int i = 0; i < OurObj.rows; i++) {
				for (int j = 0; j < OurObj.colums; j++) {
					OurStream >> OurObj.OurMatrix[i][j];
				}
			}
		}
		else {
			throw "Matrix isn't initialazed\n";
		}
	}
	catch (const char* ExceptionString) {
		std::cout << ExceptionString;
	}
	return OurStream;
}




template <class Template>
inline Matrix<Template>& operator-(Matrix<Template> & Left,  Matrix<Template> & Right)
{
	static Matrix <Template> Result;
	try {
		if (Left.OurMatrix != nullptr && Right.OurMatrix != nullptr) {
			if (Right.rows != Left.rows || Right.colums != Left.colums) {
				throw "Left Size != Right Size\n";
			}
			Result.resize(Right.rows, Right.colums);
			for (int i = 0; i < Right.rows; i++) {
				for (int j = 0; j < Right.colums; j++) {
					Result.OurMatrix[i][j] = Left.OurMatrix[i][j] - Right.OurMatrix[i][j];
				}
			}
		}
		else {
			throw "Matrix isn't initialazed\n";
		}
	}
	catch (const char* ExceptionString) {
		std::cout << ExceptionString;
	}
	return Result;

}

template<class Template>
inline Matrix<Template>& Matrix<Template>::operator=(Matrix<Template>& Right)
{
	try {
		if (Right.OurMatrix != nullptr) {
			this->resize(Right.rows, Right.colums);
			for (int i = 0; i < Right.rows; i++) {
				for (int j = 0; j < Right.colums; j++) {
					this->OurMatrix[i][j] = Right.OurMatrix[i][j];
				}
			}
		}
		else {
			throw "Matrix isn't initialazed\n";
		}
	}
	catch (const char* ExceptionString) {
		std::cout << ExceptionString;
	}
}


inline void Matrix<ComplexNumber>::rand_value()
{
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->colums; j++) {
			this->OurMatrix[i][j].rand_value();
		}

	}
}

inline void Matrix<IntervalNumber>::rand_value()
{
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->colums; j++) {
			this->OurMatrix[i][j].rand_value();
		}

	}
}

template<class Template>
inline Matrix<Template>::Matrix()
{
	this->OurMatrix = nullptr;
}

template<class Template>
inline Matrix<Template>::Matrix(int rows, int colums)
{
	this->rows = rows;
	this->colums = colums;
	this->OurMatrix = new Template * [rows];
	for (int i = 0; i < rows; i++) {
		this->OurMatrix[i] = new Template[colums];
	}
}

template<class Template>
inline Matrix<Template>::~Matrix()
{
	if (this->OurMatrix != nullptr) {
		for (int i = 0; i < this->rows; i++) {
			delete[] this->OurMatrix[i];
			this->OurMatrix[i] = nullptr;
		}
		delete[] this->OurMatrix;
		this->OurMatrix = nullptr;
	}
}

template<class Template>
inline void Matrix<Template>::resize(int rows, int colums)
{
	this->rows = rows;
	this->colums = colums;
	this->OurMatrix = new Template * [rows];
	for (int i = 0; i < rows; i++) {
		this->OurMatrix[i] = new Template[colums];
	}
}

#endif // !MATRIX.H



