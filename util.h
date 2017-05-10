#ifndef UTIL_H
#define UTIL_H

#include <chrono>
#include <iostream>

using std::istream;

class Timer{
private:
    /* start the timer */
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    
public:
    
    /*
     * Function called when starting the timer.
     */
    void begin_timer();
    
    /*
     * Function called when ending the timer. Returns duration in nanoseconds
     * PRECONDITION: begin_timer() must be called before this function
     */
    long long end_timer();
};

#endif //UTIL_H
