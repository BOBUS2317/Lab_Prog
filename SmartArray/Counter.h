#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int count;
    int min_limit;
    int max_limit;

public:
    Counter(int min, int max);
    void increment();
    void decrement();
    int getCurrent() const;
};

#endif