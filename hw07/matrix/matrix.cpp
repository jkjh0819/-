#include "matrix.h"


Matrix::Matrix()
{
	rows_ = 0; cols_ = 0;
}
Matrix::Matrix(const Matrix& m)
{
	rows_ = m.rows();
	cols_ = m.cols();
	values_ = m.values_;
}
Matrix::Matrix(int rows, int cols)
{
	rows_ = rows;
	cols_ = cols;
	Resize(rows_, cols_);
}
	
int& Matrix::operator()(int r, int c)
{
	return values_[Sub2Ind(r, c)];
}

const int& Matrix::operator()(int r, int c) const
{
	return values_[Sub2Ind(r, c)];
}

Matrix Matrix::operator +() const
{
	Matrix temp(rows_, cols_);
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			temp(i, j) = values_[i + j*rows_];	//i,j위치에 기존 값을 넣어준다.
	return temp;
} 

Matrix Matrix::operator -() const
{
	Matrix temp(rows_, cols_);
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_;j++)
			temp(i, j) = (values_[i+j*rows_] * (-1));

	return temp;
}

Matrix Matrix::Transpose() const
{
	Matrix temp(cols_, rows_);
	for (int i = 0; i < cols_; i++)
		for (int j = 0; j < rows_; j++)
			temp.values_[i+j*cols_]=values_[j+i*rows_];
	return temp;
}


istream& operator>>(istream& is, Matrix& m)
{
	int rows, cols;
	is >> rows >> cols;
	m.Resize(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			is >> m(i, j);
	}
	return is;
}
ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.rows(); i++)
	{
		for (int j = 0; j < m.cols(); j++)
		{
			os << m(i, j) << ' ';
		}
		os << endl;
	}
	return os;
}
// 행렬연산. 왼쪽 행렬과 오른쪽 행렬의 크기가 맞지 않아 계산이 되지 않는 경우
// cout << "Invalid operation" << endl; 을 출력하고 프로그램을 종료
// (exit(0) 함수).
Matrix operator+(const Matrix& lm, const Matrix& rm)
{
	if ((lm.rows() != rm.rows()) || (lm.cols() != rm.cols()))
	{
		cout << "Invalid operation" << endl;
		exit(0);
	}
	Matrix temp(lm.rows(),lm.cols());
	for (int i = 0; i < lm.rows(); i++)
	{
		for (int j = 0; j < lm.cols(); j++)
			temp(i,j) = lm(i, j) + rm(i, j);
	}
	return temp;
	
}
Matrix operator-(const Matrix& lm, const Matrix& rm)
{
	if ((lm.rows() != rm.rows()) || (lm.cols() != rm.cols()))
	{
		cout << "Invalid operation" << endl;
		exit(0);
	}
	Matrix temp(lm.rows(), lm.cols());
	for (int i = 0; i < lm.rows(); i++)
	{
		for (int j = 0; j < lm.cols(); j++)
			temp(i, j) = lm(i, j) - rm(i, j);
	}
	return temp;
}

Matrix operator*(const Matrix& lm, const Matrix& rm)	//행렬 곱연산
{
	if ((lm.cols() != rm.rows()))
	{
		cout << "Invalid operation" << endl;
		exit(0);
	}
	Matrix temp(lm.rows(), rm.cols());
	for (int i = 0; i < lm.rows(); i++)
	{
		for (int j = 0; j < rm.cols(); j++)
		{
			int multi = 0;
			for (int k = 0; k < lm.cols(); k++)	//왼쪽 행렬의 행과 오른쪽 행렬의 열을 돌면서 값을 계산한다.
			{
				multi += lm(i, k)*rm(k, j);
			}
			temp(i, j) = multi;
		}
	}
	return temp;
}
Matrix operator+(const int& a, const Matrix& rm)
{
	Matrix temp(rm.rows(), rm.cols());
	for (int i = 0; i < rm.rows(); i++)
	{
		for (int j = 0; j < rm.cols(); j++)
			temp(i, j) = a + rm(i, j);
	}
	return temp;
}
Matrix operator-(const int& a, const Matrix& rm)
{
	Matrix temp(rm.rows(), rm.cols());
	for (int i = 0; i < rm.rows(); i++)
	{
		for (int j = 0; j < rm.cols(); j++)
			temp(i, j) = a - rm(i, j);
	}
	return temp;
}
Matrix operator*(const int& a, const Matrix& rm)
{
	Matrix temp(rm.rows(), rm.cols());
	for (int i = 0; i < rm.rows(); i++)
	{
		for (int j = 0; j < rm.cols(); j++)
			temp(i, j) = a * rm(i, j);
	}
	return temp;
}
Matrix operator+(const Matrix& lm, const int& a)
{
	Matrix temp(lm.rows(), lm.cols());
	for (int i = 0; i < lm.rows(); i++)
	{
		for (int j = 0; j < lm.cols(); j++)
			temp(i, j) = lm(i, j) + a;
	}
	return temp;
}
Matrix operator-(const Matrix& lm, const int& a)
{
	Matrix temp(lm.rows(), lm.cols());
	for (int i = 0; i < lm.rows(); i++)
	{
		for (int j = 0; j < lm.cols(); j++)
			temp(i, j) = lm(i, j) - a;
	}
	return temp;
}
Matrix operator*(const Matrix& lm, const int& a)
{
	Matrix temp(lm.rows(), lm.cols());
	for (int i = 0; i < lm.rows(); i++)
	{
		for (int j = 0; j < lm.cols(); j++)
			temp(i, j) = lm(i, j) * a;
	}
	return temp;
}