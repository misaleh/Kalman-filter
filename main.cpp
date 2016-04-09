#include <iostream>
#include "kalman.hpp"
using namespace std;

int main()
{
int i = 0;
double tempvalue = 0;
Kalman1d temprature(5,20);
for(i = 0; i  < 22 ; i++)
{
	temprature.Update((double)3 , double(30 + i%3));
	tempvalue = temprature.Compute();
	cout << "tempvalue[" << i << "] " << "= " << tempvalue  << endl;
}

	cout << "Final Value = " << tempvalue << endl; 
return 0;
}

