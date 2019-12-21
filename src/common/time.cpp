#include "./time.hpp"

std::chrono::high_resolution_clock::time_point init_timepoint =
    std::chrono::high_resolution_clock::now();

int64_t intervalMs(std::chrono::high_resolution_clock::time_point end,
                   std::chrono::high_resolution_clock::time_point start)
{
    std::chrono::duration<double> time_span = end - start;
    std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(time_span);
    return d.count();
}

int64_t timeBootMs(void)
{
    return intervalMs(std::chrono::high_resolution_clock::now(), init_timepoint);
}