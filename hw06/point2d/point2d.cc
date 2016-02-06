#include "point2d.h"


Point::Point()
{
	this->x_ = 0;
	this->y_ = 0;
}
Point::Point(const Point& p)
{
	this->x_ = p.x_;
	this->y_ = p.y_;
}
Point::Point(int x, int y)
{
	this->x_ = x;
	this->y_ = y;
}
Point::Point(int c)
{
	this->x_ = c;
	this->y_ = c;
}

Point Point::operator-() const
{
	return Point(-x_, -y_);
}
Point operator+(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}
Point operator-(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
}
Point operator*(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x_ * rhs.x_, lhs.y_ * rhs.y_);
}

