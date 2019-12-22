#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <chrono>

int64_t intervalMs(std::chrono::high_resolution_clock::time_point end,
                   std::chrono::high_resolution_clock::time_point start);
int64_t timeBootMs(void);

#endif