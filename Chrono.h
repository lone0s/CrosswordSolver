#ifndef CHRONO_CHRONO_H
#define CHRONO_CHRONO_H


#include <ctime>
#include <cstdio>

class Chrono {
private:
    double secondsPassed;
    clock_t clock;
    bool clockIsRunning;

public:
    Chrono();
    void start();
    void end();
    std::string howMuchTimePassed() const;
private:
    void calculateTimePassed(const clock_t &start, const clock_t &end);
};


#endif //CHRONO_CHRONO_H
