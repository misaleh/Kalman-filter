#ifndef MATRIX_HPP
#define MATRIX_HPP
/*
simple matrix class
indexing starts from 0,0

*/

class Matrix{
	public:
		Matrix(int rows,int cols); //default values equal to zero
		~Matrix();
		int getRows(void);
		int getCols(void);
		double getVal(int r , int c);
		void setVal(int r,int c,double val);
		short int mult(Matrix *B , Matrix *C); //should be in order 
		void print(void);
	private:
		unsigned int _cols;
		unsigned int _rows;
		double *_data;

};


#endif