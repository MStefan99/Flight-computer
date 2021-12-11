/* 
 * File:   common.h
 * Author: mikha
 *
 * Created on December 11, 2021, 11:44 AM
 */

#ifndef COMMON_H
#define	COMMON_H


#define MAP(x1, y1, x2, y2, value) ((value - x1) * (y2 - x2) / (y1 - x1) + x2)
#define AVG(a, b) ((a + b) / 2)
#define ABS(a) ((a > 0)? (a) : -(a))
#define MIN(a, b) ((a < b)? (a) : (b))
#define MAX(a, b) ((a > b)? (a) : (b))
#define SWAP(a, b) {\
  auto t {a};  \
  a = b;  \
  b = t;\
}


#endif	/* COMMON_H */

