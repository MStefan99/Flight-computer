/* 
 * File:   InlineMatrix.hpp
 * Author: Mikhail
 *
 * Created on May 4, 2024, 1:03 PM
 */

#ifndef INLINEMATRIX_HPP
#define	INLINEMATRIX_HPP

#include "device.h"

#include "Matrix.hpp"

template <class scalar = float, class size_type = unsigned int, size_type h = 1, size_type w = 1>
class InlineMatrix : public Matrix<scalar, size_type, h, w> {
public:
    constexpr InlineMatrix() = delete;
    constexpr explicit InlineMatrix(scalar values[h * w]);
	constexpr InlineMatrix(const std::initializer_list<std::initializer_list<scalar>>& values) = delete;
	constexpr InlineMatrix(const InlineMatrix& matrix) = delete;
	constexpr InlineMatrix& operator=(const InlineMatrix& matrix) = delete;
    
protected:
    scalar* _values;
};

template <class scalar, class size_type, size_type h, size_type w>
constexpr InlineMatrix<scalar, size_type, h, w>::InlineMatrix(scalar values[h * w]) {
    _values = values;
}

#endif	/* INLINEMATRIX_HPP */

