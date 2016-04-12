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

class Kalmanmv//apply kalman filter for multi variable system
{
public:
	//Kalman1v(int **xk0 , int **pk0 ,);// intial state and covarince , A , B  , u ,matrices
	//void Update();
	//double Compute(void);
private:
	//double _KalmanGain;       //kalman gain (KG)
	void MatrixMult(int **matrix1,int r1,int c1,int **matrix2,int r2,int c2,int **Output); //matrix multiplication
};

#endif

