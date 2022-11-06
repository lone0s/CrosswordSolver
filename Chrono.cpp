#include <iostream>
#include "Chrono.h"

Chrono::Chrono() {
    secondsPassed = 0;
    clockIsRunning = false;
}

void Chrono::start() {
    if (!clockIsRunning) {
        clockIsRunning = true;
        Chrono::clock = std::clock();
    } else
        std::cerr << "Clock hasn't been stopped !" << std::endl;
}

void Chrono::end() {
    if (clockIsRunning){
        clock_t end = clock - std::clock();
        calculateTimePassed(clock,end);
        clockIsRunning = false;
    } else
        std::cerr << "Clock hasn't been started !" << std::endl;
}


void Chrono::calculateTimePassed(const clock_t &start, const clock_t &end) {
    Chrono::secondsPassed = (((double)start-end)/CLOCKS_PER_SEC);
}

std::string Chrono::howMuchTimePassed() const {
    return ("Run time: " + std::to_string(secondsPassed));
}
