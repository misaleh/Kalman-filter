/*
This is kalman filter libarary that does not need any libraries

Author: Mostafa Saleh
Email: moustafa.i.saleh@gmail.com
*/



#include <iostream>
#include "kalman.hpp"
#include "matrix.hpp"

using namespace std;


int main()
{

/********************** KALMAN 1 variable test *************************/
int i = 0;
double tempvalue = 0;
Kalman1v temprature(5,20); // as temprature sesnor
for(i = 0; i  < 22 ; i++)
{
	temprature.Update((double)3 , double(30 + i%6)); // measurment error is constant, temp varies from 30 36 (as it is 33)
	tempvalue = temprature.Compute(); //compute the new value
	cout << "tempvalue[" << i << "] " << "= " << tempvalue  << endl; //print values
}
/********************** Matrix test***********************/	
Matrix A(2,4);
Matrix B(4,2);
Matrix C(2,2);
int count = 0;
// fill A and B
for(int i = 0; i < 2 ; i++)
	for(int j= 0 ; j < 4; j++)
		A.setVal(i,j,++count);
count = 0 ;
for(int i = 0; i < 4 ; i++)
	for(int j= 0 ; j < 2; j++)
		B.setVal(i,j,++count);
//multiplying
A.mult(&B,&C);
std::cout<<"here\n";
// printing output
A.print();
std::cout<<"\n";
B.print();
std::cout<<"\n";
C.print();
std::cout<<"\n";
/*********************** Kalaman multi variable test *****************/

return 0;
}

