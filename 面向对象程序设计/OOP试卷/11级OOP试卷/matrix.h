// mat.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T> class Matrix
{
public:
	Matrix(int Row=0, int Col=0, const T *mat=NULL) : row(Row), col(Col), x(NULL)
	{
		if(Row<=0 || Col<=0)
			row = col = 0;
		else
		{
			x = new T[row*col];
			for(int i=row*col-1; i>=0; i--)
				x[i] = (mat!=NULL) ? mat[i] : T(0);
		}
	}
	Matrix(const Matrix &mat) : x(NULL)
	{
		*this = mat;
	}
	virtual ~Matrix()
	{
		if(x!=NULL) delete [] x;
	}
	Matrix & operator=(const Matrix &mat)
	{
		if(&mat==this) return *this;
		if(x!=NULL) delete [] x;
		row = mat.row;
		col = mat.col;
		if(row<=0 || col<=0)
			x = NULL;
		else
		{
			x = new T[row*col];
			for(int i=row*col-1; i>=0; i--)
				x[i] = mat.x[i];
		}
		return *this;
	}
	int Row() const { return row; }
	int Col() const { return col; }
	friend ostream & operator<<(ostream &out, const Matrix &mat)
	{
		for(int i=0; i<mat.row; i++)
		{
			out << '[';
			for(int j=0; j<mat.col; j++)
				out << setw(6) << mat.x[i*mat.col+j];
			out << ']' << endl;
		}
		return out;
	}
	T * operator[](int index)
	{
		return x + index * col;
	}
protected:
	int row, col;
	T *x;
};

#endif
