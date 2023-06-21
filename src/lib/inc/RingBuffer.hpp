//
// Created by mikha on 30.11.21.
//

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <cstdint>

#include "tl/allocator.hpp"


template<class T, class Alloc = tl::allocator<T>>
class RingBuffer {
public:
	using value_type = T;
	using allocator_type = Alloc;

	using pointer = typename allocator_type::pointer;
	using const_pointer = typename allocator_type::const_pointer;
	using reference = typename allocator_type::reference;
	using const_reference = typename allocator_type::const_reference;

	using difference_type = typename allocator_type::difference_type;
	using size_type = typename allocator_type::size_type;

	explicit RingBuffer(size_type capacity = 0);
	RingBuffer(const RingBuffer& buffer, size_type capacity = 0);
	~RingBuffer();

	void push_front(const_reference value);
	void push_back(const_reference value);

	void pop_front(size_type amount = 1);
	void pop_back(size_type amount = 1);

	reference front();
	reference back();

	size_type size() const;
	size_type capacity() const;

	bool empty() const;
	bool full() const;

	void resize(size_type capacity);
	void clear();

	pointer data();
	const_pointer data() const;
	size_type contiguous() const;

	reference operator[](size_type index);
	RingBuffer& operator=(const RingBuffer& buffer) = default;

protected:
	T* _elements;
	size_type _front {0};
	size_type _back {0};
	size_type _size {0};
	size_type _capacity {0};
};


template<class T, class Alloc>
RingBuffer<T, Alloc>::RingBuffer(size_type capacity): _capacity {capacity} {
	// Nothing to do
}


template<class T, class Alloc>
RingBuffer<T, Alloc>::RingBuffer(const RingBuffer& buffer, size_type capacity): _elements {buffer._elements},
		_capacity {capacity} {
	// Nothing to do
}


template<class T, class Alloc>
RingBuffer<T, Alloc>::~RingBuffer() {
	for (size_type i {0}; i < _capacity; ++i) {
		allocator_type().destroy(_elements + i);
	}
	allocator_type().deallocate(_elements, _capacity);
}


template<class T, class Alloc>
void RingBuffer<T, Alloc>::push_back(const_reference value) {
	if (_size == _capacity) {
		pop_front();
	}

	if (_size) {
		_back = (_back + 1) % _capacity;
	}
	_elements[_back] = value;
	++_size;
}


template<class T, class Alloc>
void RingBuffer<T, Alloc>::push_front(const_reference value) {
	if (_size == _capacity) {
		pop_back();
	}

	if (_size) {
		_front = (_front + _capacity - 1) % _capacity;
	}
	_elements[_front] = value;
	++_size;
}


template<class T, class Alloc>
void RingBuffer<T, Alloc>::pop_back(size_type amount) {
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


template<class T, class Alloc>
void RingBuffer<T, Alloc>::pop_front(size_type amount) {
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


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::reference RingBuffer<T, Alloc>::back() {
	return _elements[_back];
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::reference RingBuffer<T, Alloc>::front() {
	return _elements[_front];
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::size_type RingBuffer<T, Alloc>::size() const {
	return _size;
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::size_type RingBuffer<T, Alloc>::capacity() const {
	return _capacity;
}


template<class T, class Alloc>
bool RingBuffer<T, Alloc>::empty() const {
	return !_size;
}


template<class T, class Alloc>
bool RingBuffer<T, Alloc>::full() const {
	return _size == _capacity;
}


template<class T, class Alloc>
void RingBuffer<T, Alloc>::resize(size_type capacity) {
	pointer newElements = allocator_type().allocate(capacity);
	for (size_type i {0}; i < capacity; ++i) {
		allocator_type().construct(newElements + i);
	}

	size_type newSize = capacity < _size ? capacity : _size;
	for (size_type i {0}, front {_front}; i < newSize; front = (front + 1) % _capacity, ++i) {
		newElements[i] = _elements[front];
	}

	for (size_type i {0}; i < _capacity; ++i) {
		allocator_type().destroy(_elements + i);
	}
	allocator_type().deallocate(_elements, _capacity);

	_elements = newElements;
	_front = 0;
	_back = newSize ? newSize - 1 : 0;
	_size = newSize;
	_capacity = capacity;
}


template<class T, class Alloc>
void RingBuffer<T, Alloc>::clear() {
	_front = _back = _size = 0;
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::pointer RingBuffer<T, Alloc>::data() {
	return _elements + _front;
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::const_pointer RingBuffer<T, Alloc>::data() const {
	return _elements;
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::size_type RingBuffer<T, Alloc>::contiguous() const {
	size_type dist = _capacity - _front;
	return _size < dist ? _size : dist;
}


template<class T, class Alloc>
typename RingBuffer<T, Alloc>::reference RingBuffer<T, Alloc>::operator[](size_type index) {
	return _elements[(_front + index) % _capacity];
}


#endif //RINGBUFFER_H
