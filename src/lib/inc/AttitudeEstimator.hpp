//
// Created by MStefan99 on 21.3.22.
//

#ifndef FILTERS_ATTITUDEESTIMATOR_H
#define FILTERS_ATTITUDEESTIMATOR_H

#include <cmath>

#include "EKF.hpp"
#include "util.hpp"


#define USE_KALMAN ( false )


class AttitudeEstimator {
public:
	explicit AttitudeEstimator(float accUncertainty = 0.1);
	void init(float roll, float pitch);

	//void update(float dt);  // TODO: remove?
	void measure(
			const Matrix& rot,
			const Matrix& acc,
			float dt);

	float getRoll() const;
	float getPitch() const;

#if USE_KALMAN
	Matrix getUncertainty() const;
#endif

protected:
#if USE_KALMAN
	Matrix _u {};

	EKF _k;
#else 
	float _roll {0};
	float _pitch {0};
#endif
};


#endif //FILTERS_ATTITUDEESTIMATOR_H
