//
// Created by MStefan99 on 29.3.22.
//

#include "lib/inc/EKF.h"
#include "device.h"


EKF::EKF(const Matrix& Q, const Matrix& R):
		_q {Q}, _r {R} {
	// Nothing to do
}


void EKF::init(const Matrix& P,
		const Matrix& xe,
		const Matrix& F) {
	_x = xe;
	_p = F * P * F.transpose() + _q;
}


void EKF::extrapolateState(const Matrix& xe, const Matrix& F) {
	_x = xe;
	_p = F * _p * F.transpose() + _q;
}


void EKF::updateState(const Matrix& H, const Matrix& z, const Matrix& out) {
	Matrix K {_p * H.transpose() * (H * _p * H.transpose() + _r).invert()};  // 6.5ms @ 8MHz, invert - 2ms
	_x = _x + K * (z - out);  // 1ms @ 8MHz

	Matrix temp {Matrix::identity(_x.getHeight()) - K * H};  // 1ms @ 8MHz
	_p = temp * _p;  // 600us @ 8MHz
}


Matrix EKF::getState() const {
	return _x;
}


Matrix EKF::getCovariance() const {
	return _p;
}