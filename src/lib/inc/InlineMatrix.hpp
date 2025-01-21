/*
 * File:   InlineMatrix.hpp
 * Author: Mikhail
 *
 * Created on May 4, 2024, 1:03 PM
 */

#ifndef INLINEMATRIX_HPP
#define INLINEMATRIX_HPP

#include "device.h"

#include "Matrix.hpp"

template <class scalar = float, class size_type = unsigned int, size_type h = 1, size_type w = 1>
class InlineMatrix: public Matrix<scalar, size_type, h, w> {
public:
	InlineMatrix() = delete;
	explicit InlineMatrix(scalar* values);
	InlineMatrix(const std::initializer_list<std::initializer_list<scalar>>& values) = delete;
	InlineMatrix(const InlineMatrix& matrix) = delete;

	InlineMatrix& operator= (const Matrix<scalar, size_type, h, w>& matrix);

	scalar*       operator[] (size_type i) override;
	const scalar* operator[] (size_type i) const override;

protected:
	scalar* _values {nullptr};
};

template <class scalar, class size_type, size_type h, size_type w>
InlineMatrix<scalar, size_type, h, w>::InlineMatrix(scalar* values) {
	_values = values;
}

template <class scalar, class size_type, size_type h, size_type w>
scalar* InlineMatrix<scalar, size_type, h, w>::operator[] (size_type i) {
	return _values + (i * w);
}

template <class scalar, class size_type, size_type h, size_type w>
const scalar* InlineMatrix<scalar, size_type, h, w>::operator[] (size_type i) const {
	return _values + (i * w);
}

template <class scalar, class size_type, size_type h, size_type w>
InlineMatrix<scalar, size_type, h, w>&
    InlineMatrix<scalar, size_type, h, w>::operator= (const Matrix<scalar, size_type, h, w>& matrix) {
	if (this != &matrix) {
		for (size_type j {0}; j < h; ++j) {
			for (size_type i {0}; i < w; ++i) {
				this->operator[] (j)[i] = matrix[j][i];
			}
		}
	}
	return *this;
}

#endif /* INLINEMATRIX_HPP */
