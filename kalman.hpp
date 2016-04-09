#ifndef KALMAN_H
#define KALMAN_H
class Kalman1d/*apply kalman filter for 1 variable system (1d)*/
{
public:
	Kalman1d(double EstimateErrorInit ,double EstimateValueInit); /*Constructor, inital error in estimation and intal intial estimation as arguments */
	void Update(double MeasurmentError, double MeasurmentValue);/*update the values of measurment and its error*/
	double Compute(void);/*calculate gain and new estimate value and new estimate error, returns the estimate value*/
private:
	double _EstimateError;
	double _EstimateValue;
	double _MeasurmentValue;
	double _MeasurmentError;
	double _EstimateErrorOld;
	double _EstimateValueOld;
	double _KalmanGain;
};
#endif

