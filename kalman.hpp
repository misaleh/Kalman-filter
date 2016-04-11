#ifndef KALMAN_H
#define KALMAN_H
class Kalman1v/*apply kalman filter for 1 variable system */
{
public:
	Kalman1v(double EstimateErrorInit ,double EstimateValueInit); /*Constructor, inital error in estimation and intal intial estimation as arguments */
	void Update(double MeasurmentError, double MeasurmentValue);/*update the values of measurment and its error*/
	double Compute(void);/*calculate gain and new estimate value and new estimate error, returns the estimate value*/
private:
	double _EstimateError; // Error in estimation (Eest)
	double _EstimateValue; // Estimated value (Est)
	double _MeasurmentValue; // Measured value (MEA)
	double _MeasurmentError; // Measurment error (Emea)
	double _EstimateErrorOld; // Eest at t-1
	double _EstimateValueOld; // Est at t-1
	double _KalmanGain;       //kalman gain (KG)
};
#endif

