#include "DigitalClock.h"
#include <iostream>
#include <iomanip>

DigitalClock::DigitalClock(int h, int m, int s) {
    hours = (h >= 0 && h < 24) ? h : 0;
    minutes = (m >= 0 && m < 60) ? m : 0;
    seconds = (s >= 0 && s < 60) ? s : 0;
}

DigitalClock::~DigitalClock() {
    std::cout << "---Clock deleted---" << std::endl;
}

void DigitalClock::display() const {
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setfill('0') << std::setw(2) << minutes << ":"
              << std::setfill('0') << std::setw(2) << seconds << std::endl;
}

void DigitalClock::tick() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hours++;
            if (hours >= 24) hours = 0;
        }
    }
}