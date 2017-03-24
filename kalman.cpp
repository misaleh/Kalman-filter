#include "kalman.hpp"
#include "matrix.hpp"
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


