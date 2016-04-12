#include <iostream>
#include "kalman.hpp"
using namespace std;


int main()
{
int mat1[2][2] = {{1, 0},{0, 1}};
int mat2[2][2] ={{1, 2},{1, 3}};
int  mat3[2][2];
int *mat1p[2] = {&mat1[0][0], &mat1[1][0]};
int *mat2p[2] = {&mat2[0][0], &mat2[1][0]};
int *mat3p[2] = {&mat3[0][0], &mat3[1][0]};
int **mat1pp = &mat1p[0]; 
int **mat2pp = &mat2p[0];
int **mat3pp = &mat3p[0];
int i = 0;
double tempvalue = 0;
Kalman1v temprature(5,20); // as temprature sesnor

for(i = 0; i  < 22 ; i++)
{
	temprature.Update((double)3 , double(30 + i%6)); // measurment error is constant, temp varies from 30 36 (as it is 33)
	tempvalue = temprature.Compute(); //compute the new value
	cout << "tempvalue[" << i << "] " << "= " << tempvalue  << endl; //print values
}
	//MatrixMult(mat1pp,2,2,mat2pp,2,2,mat3pp);
	
return 0;
}

