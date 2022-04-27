//
// Created by MStefan99 on 21.3.22.
//

#include "lib/inc/AttitudeEstimator.hpp"

#if USE_KALMAN

#define processNoise 0.005f
#define g 9.81f

#define phi x[0][0]
#define theta x[1][0]

#define p _u[0][0]
#define q _u[1][0]
#define r _u[2][0]

#define trig() \
  float sin_phi = sinf(phi); \
  float cos_phi = cosf(phi); \
  float sin_theta = sinf(theta); \
  float cos_theta = cosf(theta); \
  float tan_theta = tanf(theta); \
  float tan_s = tan_theta * tan_theta + 1

#define xe {\
  {phi + (p + q * sin_phi * tan_theta + r * cos_phi * tan_theta) * dt},\
  {theta + (q * cos_phi + r * sin_phi) * dt}\
}


#define out {\
  {-g * sin_theta},\
  {g * cos_theta * sin_phi},\
  {g * cos_theta * cos_phi}\
}


#define F {\
  {dt * (q * cos_phi * tan_theta - r * sin_phi * tan_theta) + 1,\
  dt * (r * cos_phi * tan_s + q * sin_phi * tan_s)},\
  {dt * (r * cos_phi - q * sin_phi), 1}\
}


#define H {\
  {0, -g * cos_theta},\
  {g * cos_phi * cos_theta, -g * sin_phi * sin_theta},\
  {-g * cos_theta * sin_phi, -g * cos_phi * sin_theta}\
}


AttitudeEstimator::AttitudeEstimator(float accUncertainty):
		_k {
				{
						{processNoise, 0},
						{0, processNoise}
				},
				{
						{accUncertainty, 0, 0},
						{0, accUncertainty, 0},
						{0, 0, accUncertainty}
				}
		} {
// Nothing to do
}


void AttitudeEstimator::init(float roll, float pitch) {
	_k.init(
			{
					{PI, 0},
					{0, PI}
			},
			{
					{roll},
					{pitch}
			},
			{
					{0},
					{0},
					{g}
			}
	);
}


void AttitudeEstimator::update(float dt) {
	const Matrix& x = _k.getState();
	trig();

	_k.extrapolateState(xe, F);
}


void AttitudeEstimator::measure(const Matrix& rot, const Matrix& acc, float dt) {
	const Matrix& x = _k.getState();

	trig(); // 2ms @ 8MHz
	_u = rot;
	_k.extrapolateState(xe, F); // 3ms @ 8MHz
  trig()
	_k.updateState(H, acc, out); // 10ms @ 8MHz
}


float AttitudeEstimator::getRoll() const {
	return _k.getState()[0][0];
}


float AttitudeEstimator::getPitch() const {
	return _k.getState()[1][0];
}


Matrix AttitudeEstimator::getUncertainty() const {
	return _k.getCovariance();
}
#endif

#define ALPHA ( 0.3 )


AttitudeEstimator::AttitudeEstimator(float accUncertainty) {
	// Nothing to do
}


void AttitudeEstimator::init(float roll, float pitch) {
	_roll = roll;
	_pitch = pitch;
}


void AttitudeEstimator::measure(const Matrix& rot, const Matrix& acc, float dt) {
	_pitch += rot[1][0] * dt;
	_roll += rot[0][0] * dt;

	float pitchAcc = atan2f(acc[0][0], acc[2][0]);
	_pitch = std::fmod(_pitch * (1 - ALPHA) - pitchAcc * ALPHA, PI);

	float rollAcc = atan2f(acc[1][0], acc[2][0]);
	_roll = std::fmod(_roll * (1 - ALPHA) + rollAcc * ALPHA, PI);
}


float AttitudeEstimator::getRoll() const {
	return _roll;
}


float AttitudeEstimator::getPitch() const {
	return _pitch;
}