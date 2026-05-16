#include "DigitalClock.h"
#include <iostream>

int main(int, char **)
{   
    DigitalClock clock(23, 55, 1);
    std::cout<<"Created clock: hours = 23 minutes = 55 seconds = 1"<<std::endl;
    std::cout<<"---Display---"<<std::endl;
    clock.display();

    std::cout<<"---Clock ticks---"<<std::endl;
    for (unsigned int i = 0; i < 320; i++)
    {
        clock.tick();
        if (i % 10 == 0)
            clock.display();
    }
    
    DigitalClock brokenClock(0, 00, 20);
    std::cout<<"Clock delets in: hours = 0 minutes = 00 seconds = 20"<<std::endl;
    brokenClock.display();
            

    return 0;
}