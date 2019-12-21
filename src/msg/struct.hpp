#ifndef _MSG_HPP_
#define _MSG_HPP_

#include <chrono>

struct Position
{
    float x_m;
    float y_m;
    float z_m;
    int64_t time_boot_ms;
};

struct Velocity
{
    float x_ms;
    float y_ms;
    float z_ms;
    int64_t time_boot_ms;
};

#endif