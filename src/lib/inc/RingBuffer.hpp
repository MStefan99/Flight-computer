//
// Created by mikha on 30.11.21.
//

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <cstdint>

template <class T>
class RingBuffer {
public:
	using size_type = uint16_t;
	
	RingBuffer() = default;
	RingBuffer(const RingBuffer& buffer) = default;
	~RingBuffer() = default;

	void push_front(const T& value);
	void push_back(const T& value);

	void pop_front(size_type amount = 1);
	void pop_back(size_type amount = 1);

	T& front();
	T& back();

	size_type size() const;
	size_type capacity() const;

	bool empty() const;
	bool full() const;

	void resize(size_type capacity);
	void clear();

	T* data();
	const T* data() const;
	size_type contiguous() const;

	T& operator[](size_type index);
	RingBuffer& operator=(const RingBuffer& buffer) = default;

protected:
	T* _elements;
	size_type _front {0};
	size_type _back {0};
	size_type _size {0};
	size_type _capacity {0};
};


template <class T>
void RingBuffer<T>::push_back(const T& value) {
	if (_size == _capacity) {
		resize(_size + 1);
	}

	if (_size) {
		_back = (_back + 1) % _capacity;
	}
	_elements[_back] = value;
	++_size;
}


template <class T>
void RingBuffer<T>::push_front(const T& value) {
	if (_size == _capacity) {
		resize(_size + 1);
	}

	if (_size) {
		_front = (_front + _capacity - 1) % _capacity;
	}
	_elements[_front] = value;
	++_size;
}


template <class T>
void RingBuffer<T>::pop_back(size_type amount) {
	if (!_size) {
		return;
	}

	if (amount < _size) {
		_back = (_back + _capacity - amount) % _capacity;
		_size -= amount;
	} else {
		clear();
	}
}


template <class T>
void RingBuffer<T>::pop_front(size_type amount) {
	if (!_size) {
		return;
	}

	if (amount < size()) {
		_front = (_front + amount) % _capacity;
		_size -= amount;
	} else {
		clear();
	}
}


template <class T>
T& RingBuffer<T>::back() {
	return _elements[_back];
}


template <class T>
T& RingBuffer<T>::front() {
	return _elements[_front];
}


template <class T>
typename RingBuffer<T>::size_type RingBuffer<T>::size() const {
	return _size;
}


template <class T>
typename RingBuffer<T>::size_type RingBuffer<T>::capacity() const {
	return _capacity;
}


template <class T>
bool RingBuffer<T>::empty() const {
	return !_size;
}


template <class T>
bool RingBuffer<T>::full() const {
	return _size == _capacity;
}


template <class T>
void RingBuffer<T>::resize(size_type capacity) {
	T* newElements = new T[capacity];
	size_type newSize = capacity < _size? capacity : _size;

	for (size_type i {0}, front {_front}; i < newSize; front = (front + 1) % _capacity, ++i) {
		newElements[i] = _elements[front];
	}

	delete[] (_elements);
	_elements = newElements;
	_front = 0;
	_back = newSize? newSize - 1 : 0;
	_size = newSize;
	_capacity = capacity;
}


template <class T>
void RingBuffer<T>::clear() {
	_front = _back = _size = 0;
}


template <class T>
T* RingBuffer<T>::data() {
	return _elements + _front;
}


template <class T>
const T* RingBuffer<T>::data() const {
	return _elements;
}


template <class T>
typename RingBuffer<T>::size_type RingBuffer<T>::contiguous() const {
	size_type dist = _capacity - _front;
	return _size < dist? _size : dist;
}


template <class T>
T& RingBuffer<T>::operator[](size_type index) {
	return _elements[(_front + index) % _capacity];
}


#endif //RINGBUFFER_H
