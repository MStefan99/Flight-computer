//
// Created by MStefan99 on 25.11.19.
//

#ifndef LIST_H
#define LIST_H

template <class T>
class list {
protected:
	struct element;

public:
	list() = default;
	list(const list& list);
	~list();

	void push_back(const T& value);
	void push_front(const T& value);

	T& front() const;
	T& back() const;

	void pop_back();
	void pop_front();

	unsigned int remove(const T& value);
	unsigned int remove_if(bool (* predicate)(const T&));

	void clear();

	unsigned int size() const;
	bool empty() const;

	list& operator=(const list& list);

protected:

	struct element {
		explicit element(const T& value, element* prev, element* next);
		element(const element& listElement) = default;
		~element() = default;

		T elementValue;
		element* prevElement{nullptr};
		element* nextElement{nullptr};
	};

	element* _first{nullptr};
	element* _last{nullptr};

	void destroyElement(element* e);
	unsigned int _listSize{0};
};

template <class T>
list<T>::element::element(const T& value, element* prev, element* next) :
elementValue(value), prevElement(prev), nextElement(next) {
	// Nothing to do
}

template <class T>
list<T>::list(const list& l) {
	for (auto e{l._first}; e != nullptr; e = e->nextElement) {
	push_back(e->elementValue);
}
	_listSize = l.size();
}

template <class T>
list<T>::~list() {
	clear();
}

template <class T>
void list<T>::push_back(const T& value) {
	auto e = new element{value, _last, nullptr};

	if (!_first) {
		_first = e;
	}
	if (_last) {
		_last->nextElement = e;
	}
	_last = e;
	++_listSize;
}

template <class T>
void list<T>::push_front(const T& value) {
	auto e = new element{value, nullptr, _first};

	if (!_last) {
		_last = e;
	}
	if (_first) {
		_first->prevElement = e;
	}
	_first = e;
	++_listSize;
}

template <class T>
void list<T>::pop_back() {
	auto e{_last};
	if (e) {
		if (e->prevElement) {
			e->prevElement->nextElement = nullptr;
		} else {
			_first = nullptr;
		}

		_last = e->prevElement;
		--_listSize;
		delete e;
	}
}

template <class T>
void list<T>::pop_front() {
	auto e{_first};
	if (e) {
		if (e->nextElement) {
			e->nextElement->prevElement = nullptr;
		} else {
			_last = nullptr;
		}

		_first = e->nextElement;
		--_listSize;
		delete e;
	}
}

template <class T>
T& list<T>::front() const {
	return _first->elementValue;
}

template <class T>
T& list<T>::back() const {
	return _last->elementValue;
}

template <class T>
void list<T>::destroyElement(list<T>::element* e) {
	if (e->nextElement) {
		e->nextElement->prevElement = e->prevElement;
	} else {
		_last = e->prevElement;
	}
	if (e->prevElement) {
		e->prevElement->nextElement = e->nextElement;
	} else {
		_first = e->nextElement;
	}
	delete e;
}

template <class T>
unsigned int list<T>::remove(const T& value) {
	unsigned int i{0};
	element * e{_first};

	while (e) {
		auto temp = e;
		e = e->nextElement;
		if (temp->elementValue == value) {
			destroyElement(temp);
			++i;
			--_listSize;
		}
	}
	return i;
}

template <class T>
unsigned int list<T>::remove_if(bool (* p)(const T&)) {
	unsigned int i{0};
	element * e{_first};

	while (e) {
		auto temp = e;
		e = e->nextElement;
		if (p(temp->elementValue)) {
			destroyElement(temp);
			++i;
			--_listSize;
		}
	}
	return i;
}

template <class T>
void list<T>::clear() {
	element * e{_first};

	while (e) {
		auto temp = e;
		e = e->nextElement;
		destroyElement(temp);
		_listSize = 0;
	}
}

template <class T>
unsigned int list<T>::size() const {
	return _listSize;
}

template <class T>
bool list<T>::empty() const {
	return _first == nullptr;
}

template <class T>
list<T>& list<T>::operator=(const list& l) {
	if (this != &l) {
		clear();
		for (auto p = l._first; p != nullptr; p = p->nextElement) {
			push_back(p->elementValue);
		}
	}
	return *this;
}


#endif //LIST_H
