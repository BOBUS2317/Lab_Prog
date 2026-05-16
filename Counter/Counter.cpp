#include "Counter.h"

Counter::Counter(int min, int max) : min_limit(min), max_limit(max) {
    count = min_limit;
}

void Counter::increment() {
    if (count < max_limit) count++;
}

void Counter::decrement() {
    if (count > min_limit) count--;
}

int Counter::getCurrent() const {
    return count; // [cite: 19]
}