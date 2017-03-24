#include "matrix.hpp"
#include <cstdlib>
#include <iostream>

Matrix::Matrix(int rows, int cols)
{
	_data = (double *)malloc(rows * cols * sizeof(double));
	_rows = rows ;
	_cols = cols;
}
Matrix::~Matrix()
{
 delete[] _data;
}
inline double Matrix::getVal(int r , int c)
{
 return _data[r*_cols +c ] ;
}
inline void Matrix::setVal(int r,int c,double val)
{
 _data[r*_cols +c ]  = val;
}
int Matrix::getRows(void)
{
	return _rows;
}
int Matrix::getCols(void)
{
	return _cols;
}
short int Matrix::mult( Matrix *B, Matrix *C)
{
	if(this->getCols()  !=  B->getRows() )
	{
		return -1;
	
	}
	double element = 0 ;
	for(int i= 0 ; i < this->getRows(); i++)
	{
		for(int j = 0 ; j < B->getCols() ; j++)
		{
			for(int k= 0 ;k < B->getRows() ; k++)
			{
				element += (this->getVal(i,k) * B->getVal(k,j)) ;

			}
			C->setVal(i,j,element);
			element = 0;
		}
	}

}
void Matrix::print(void)
{
	for(int i =0 ; i < _rows ; i++)
{
	for(int j = 0 ; j < _cols; j++)
	{
		std::cout<<this->getVal(i,j)<<" ";
	}
	std::cout<<std::endl;
}

}