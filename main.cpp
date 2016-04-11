#include <iostream>
#include "kalman.hpp"
using namespace std;

int main()
{
int i = 0;
double tempvalue = 0;
Kalman1v temprature(5,20); // as temprature sesnor
for(i = 0; i  < 22 ; i++)
{
	temprature.Update((double)3 , double(30 + i%6)); // measurment error is constant, temp varies from 30 36 (as it is 33)
	tempvalue = temprature.Compute(); //compute the new value
	cout << "tempvalue[" << i << "] " << "= " << tempvalue  << endl; //print values
}

	
return 0;
}

