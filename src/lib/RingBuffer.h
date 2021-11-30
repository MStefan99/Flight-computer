//
// Created by mikha on 30.11.21.
//

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <cstdint>


template <class T, class idx = uint8_t, idx len = 5>
class RingBuffer {
public:
	RingBuffer() = default;
	RingBuffer(const RingBuffer& buffer) = default;
	~RingBuffer() = default;

	void push_front(const T& value);
	void push_back(const T& value);

	void pop_front();
	void pop_back();

	T& front();
	T& back();

	idx size() const;
	bool empty() const;
	bool full() const;
	void clear();

	RingBuffer& operator=(const RingBuffer& buffer) = default;

protected:
	T _elements[len];
	idx _frontIdx {0};
	idx _backIdx {0};
	idx _elementCount {0};
};


template <class T, class idx, idx len>
void RingBuffer<T, idx, len>::push_back(const T& value) {
	if (_elementCount == len) {
		return;
	}

	if (_elementCount) {
		_backIdx = (_backIdx + 1) % len;
	}
	_elements[_backIdx] = value;
	++_elementCount;
}


template <class T, class idx, idx len>
void RingBuffer<T, idx, len>::push_front(const T& value) {
	if (_elementCount == len) {
		return;
	}

	if (_elementCount) {
		_frontIdx = (_frontIdx + len - 1) % len;
	}
	_elements[_frontIdx] = value;
	++_elementCount;
}


template <class T, class idx, idx len>
void RingBuffer<T, idx, len>::pop_back() {
	if (!_elementCount) {
		return;
	}

	if (_elementCount > 1) {
		_backIdx = (_backIdx + len - 1) % len;
	}
	--_elementCount;
}


template <class T, class idx, idx len>
void RingBuffer<T, idx, len>::pop_front() {
	if (!_elementCount) {
		return;
	}

	if (_elementCount > 1) {
		_frontIdx = (_frontIdx + 1) % len;
	}
	--_elementCount;
}


template <class T, class idx, idx len>
T& RingBuffer<T, idx, len>::back() {
	return _elements[_backIdx];
}


template <class T, class idx, idx len>
T& RingBuffer<T, idx, len>::front() {
	return _elements[_frontIdx];
}


template <class T, class idx, idx len>
idx RingBuffer<T, idx, len>::size() const {
	return _elementCount;
}


template <class T, class idx, idx len>
bool RingBuffer<T, idx, len>::empty() const {
	return !_elementCount;
}


template <class T, class idx, idx len>
bool RingBuffer<T, idx, len>::full() const {
	return _elementCount == len;
}


template <class T, class idx, idx len>
void RingBuffer<T, idx, len>::clear() {
	_frontIdx = _backIdx = _elementCount = 0;
}


#endif //RINGBUFFER_H
