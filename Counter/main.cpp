#include <iostream>
#include "Counter.h"

int main(int, char **)
{   
    int minLimit = 30, maxLimit = 45;
    Counter counter(minLimit, maxLimit);

    std::cout<<"---Counter---"<<std::endl;
    std::cout<<"Min limit = "<<minLimit<<std::endl;
    std::cout<<"Max limit = "<<maxLimit<<std::endl;
    std::cout<<"Counter = "<<counter.getCurrent()<<std::endl;

    std::cout<<"---Increment---"<<std::endl;
    for(int i = 0; i < 25; i++)
    {
        counter.increment();
        std::cout<<counter.getCurrent()<<std::endl;
    }
        
    std::cout<<"---Decrement---"<<std::endl;
    for(int i = 0; i < 25; i++)
    {
        counter.decrement();
        std::cout<<counter.getCurrent()<<std::endl;
    }

    return 0;
}