#include "kalman.hpp"
#include <iostream>
using namespace std;

Kalman1d::Kalman1d(double EstimateErrorInit = 0,double EstimateValueInit = 0)
{
_EstimateErrorOld = EstimateErrorInit;
_EstimateValueOld = EstimateValueInit;
}
void Kalman1d::Update(double MeasurmentError , double MeasurmentValue)
{
_MeasurmentValue = MeasurmentValue;
_MeasurmentError = MeasurmentError;
}
double Kalman1d::Compute(void)
{
_KalmanGain = (_EstimateError)/(_EstimateError + _MeasurmentError); /*calculate kalman gain*/
_EstimateValue =  _EstimateValueOld +  _KalmanGain*(_MeasurmentValue - _EstimateValueOld); /*calculate estimate error*/
_EstimateError = _EstimateErrorOld*(1 - _KalmanGain); /*calculate estimate value*/
_EstimateErrorOld = _EstimateError; /*update old error*/
_EstimateValueOld = _EstimateValue; /*update old value*/
return  _EstimateValue;
}


