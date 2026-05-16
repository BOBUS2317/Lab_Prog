#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

class DigitalClock {
private:
    int hours, minutes, seconds;

public:
    DigitalClock(int h, int m, int s);
    ~DigitalClock();
    
    void display() const;
    void tick();
};

#endif