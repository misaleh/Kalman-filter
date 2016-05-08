#include "kalman.hpp"
#include <iostream>
using namespace std;

Kalman1v::Kalman1v(double EstimateErrorInit = 0,double EstimateValueInit = 0) /*constructor used for initlization*/
{
	_EstimateErrorOld = EstimateErrorInit;  //initlaize old error value(it could take any value it will not matter)
	_EstimateValueOld = EstimateValueInit;  //initlaize old value(it could take any value it will not matter)
}
void Kalman1v::Update(double MeasurmentError , double MeasurmentValue)
{
	_MeasurmentValue = MeasurmentValue; // update the measured value (ex : from sensor )
	_MeasurmentError = MeasurmentError;// update measured error (it could be constant or variable)
}
double Kalman1v::Compute(void)
{
	_KalmanGain = (_EstimateError)/(_EstimateError + _MeasurmentError); //calculate kalman gain
	_EstimateValue =  _EstimateValueOld +  _KalmanGain*(_MeasurmentValue - _EstimateValueOld); //calculate estimate error
	_EstimateError = _EstimateErrorOld*(1 - _KalmanGain); //calculate estimate value
	_EstimateErrorOld = _EstimateError; //update old error
	_EstimateValueOld = _EstimateValue; //update old value
	return  _EstimateValue;
}
Kalmanmv::Kalmanmv(double **xk0 ,int rx, int cx, double **pk0, int rp,int cp)
{
	**_xk = **xk0;
	**_pk = **pk0;
	_cx = cx;
	_rx = rx;
	_cp = cp;
	_rp = rp;
}
void Kalmanmv::Update(double **A ,double **B, double **U,double **Y,double **H)	
{
	_A = A;
	_B = B;
	_U = U;
	_Y = Y;
	_H = H;
}
void Kalmanmv::MatrixMult(double **matrix1,int r1,int c1,double **matrix2,int r2,int c2,double **Output)
{
	int i = r1; //row
 	int j = c1; //cols
	int k = 0;
	int element = 0;
	for(i = 0 ; i < r1 ; i++)
	{
			for(j = 0 ; j < c2 ; j++)
			{
				for(k  = 0 ; k < r2 ; k++)
				{
					element  += (matrix1[i][k] * matrix2[k][j]) ;

				}
			Output[i][j] = element;
			//cout <<"Output[" <<i<<"]"<<"["<<j<<"] = "<< element <<endl; //for debuging 
			element =  0;
							
			}
					
	}
    
}




