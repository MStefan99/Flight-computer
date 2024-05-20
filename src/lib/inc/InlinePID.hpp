/* 
 * File:   InlinePID.hpp
 * Author: Mikhail
 *
 * Created on May 14, 2024, 6:26 PM
 */

#ifndef INLINEPID_HPP
#define	INLINEPID_HPP

#include "util.hpp"


template <class T>
struct InlinePID {
    struct __attribute__((packed)) PIDCoefficients {
        T kp {};
        T ki {};
        T kd {};
    };

	InlinePID() = default;
	InlinePID(PIDCoefficients* coefficients, T iLim);
	InlinePID(T* kp, T* ki, T* kd, T iLim);

	T process(T val, T sp = 0, float dt = 0.01f);

	T* kp {};
	T* ki {};
	T* kd {};
	
	T iLim {};

protected:
	T _prev {};
	T _sum {};
};

template <class T>
InlinePID<T>::InlinePID(PIDCoefficients* coefficients, T iLim):
	kp {&coefficients->kp}, ki {&coefficients->ki}, kd {&coefficients->kd}, iLim {iLim} {
	// Nothing to do
}

template <class T>
InlinePID<T>::InlinePID(T* kp, T* ki, T* kd, T iLim):
	kp {kp}, ki {ki}, kd {kd}, iLim {iLim} {
	// Nothing to do
}

template <class T>
T InlinePID<T>::process(T val, T sp, float dt) {
	T error {val - sp};
	
	_sum = util::clamp(*ki * error * dt + _sum, -iLim, iLim);
	T out = *kp * error + _sum + *kd * (val - _prev) / dt;
	_prev = val;
	
	return out;
}


#endif	/* INLINEPID_HPP */

