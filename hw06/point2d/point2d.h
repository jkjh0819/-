#ifndef __hw06_point2d__
#define __hw06_point2d__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

struct Point {
	int x_, y_; 
	Point();
	Point(const Point& p);
	explicit Point(int c);
	Point(int x, int y);
	Point operator-() const;
};
Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);

#endif