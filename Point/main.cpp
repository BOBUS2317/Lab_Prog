#include "Point.h"
#include <iostream>

int main(int, char **)
{   
    double x = 5.05, y = 9.8;
    Point point1;
    Point point2(x, y);

    std::cout<<"Point 1"<<std::endl;
    point1.print();

    std::cout<<"Point 2"<<std::endl;
    point2.print();

    std::cout<<"Set point1 x = 3.14"<<std::endl;
    point1.setX(3.14);

    std::cout<<"Set point2 x = 13.32"<<std::endl;
    point1.setY(13.32);

    std::cout<<"Get X point1"<<std::endl;
    std::cout<<point1.getX()<<std::endl;
    std::cout<<"Get Y point2"<<std::endl;
    std::cout<<point2.getY()<<std::endl;

    std::cout<<"Distance to origin of point1"<<std::endl;
    std::cout<<point1.distanceToOrigin()<<std::endl;

    std::cout<<"Distance to origin of point2"<<std::endl;
    std::cout<<point2.distanceToOrigin()<<std::endl;


    return 0;
}