/* 
 * File:   PID.hpp
 * Author: MStefan99
 *
 * Created on April 23, 2022, 5:24 PM
 */

#ifndef PID_HPP
#define	PID_HPP


template <class T>
struct PID {
	PID() = default;
	PID(T p, T i, T d);

	T update(T setpoint, T current);


protected:
	float _p {};
	float _i {};
	float _d {};

	T _prev {};
	T _sum {};
};


template <class T>
PID<T>::PID(T p, T i, T d):
	_p {p}, _i{i}, _d{d} {
	// Nothing to do
}


template <class T>
T PID<T>::update(T setpoint, T current) {
	_sum += setpoint - current;
	T val = _p * (setpoint - current) + _i * _sum + _d * (current - _prev);
	_prev = current;
	
	return val;
}


#endif	/* PID_HPP */

