#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;

public:
    Point();
    Point(double xVal, double yVal);

    void setX(double xVal);
    void setY(double yVal);
    double getX() const;
    double getY() const;

    void print() const;
    double distanceToOrigin() const;
};

#endif