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
	Kalmanmv(double **xk0 ,int rx, int cx, double **pk0, int rp,int cp); // intiliaze the object , init position and state as argumnents
	// intial state and covarince matrices
	void Update(double **A ,double **B, double **U,double **Y,double **H);
	//double Compute(void);
private:
	double **_xk;
	double **_pk;
	int _rp;
	int _rx;
	int _cp;
	int _cx;
	double **_A;
	double **_B;
	double **_U;
	double **_Y;
	double **_H;

	void MatrixMult(double **matrix1,int r1,int c1,double **matrix2,int r2,int c2,double **Output); //matrix multiplication
};

#endif

