#pragma once

template <class Template>
class Matrix
{
public:
	Matrix();
	Matrix(int rows, int colums);
	~Matrix();
	void resize(int rows, int colums);
	friend std::ostream& operator<<(std::ostream&  OurStream, Matrix<Template>& OurObj);
	friend std::istream& operator>>(std::istream&  OurStream, Matrix<Template>& OurObj);
	friend Matrix<Template>& operator-(Matrix<Template>& Left, Matrix<Template>& Right);
	Matrix<Template>& operator=(Matrix<Template>& Right);
private:

	Template** OurMatrix;
	int rows, colums;
};

template <class Template>
inline std::ostream& operator<<(std::ostream& OurStream, Matrix<Template>& OurObj)
{
	try {
		if (OurObj.OurMatrix != nullptr) {
			for (int i = 0; i < OurObj.rows; i++) {
				for (int j = 0; j < OurObj.colums; j++) {
					OurStream << OurObj.OurMatrix[i][j];
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
inline std::istream& operator>>(std::istream& OurStream, Matrix<Template>& OurObj)
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
inline Matrix<Template>& operator-(Matrix<Template>& Left, Matrix<Template>& Right)
{
	static Matrix <Template> Result;
	try {
		if (Left.OurMatrix != nullptr && Right.OurMatrix !=nullptr) {
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
	if (this->OurMatrix[0] != nullptr&& this->OurMatrix != nullptr) {
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

