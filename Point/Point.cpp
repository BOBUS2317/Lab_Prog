#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() : x(0.0), y(0.0) {}
Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}

void Point::setX(double xVal) { x = xVal; }
void Point::setY(double yVal) { y = yVal; }
double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::print() const {
    std::cout << "(" << x << "; " << y << ")" << std::endl;
}

double Point::distanceToOrigin() const {
    return std::sqrt(x * x + y * y);
}