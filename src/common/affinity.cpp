#include "affinity.hpp"
#include <iostream>

void setAffinity(pthread_t native_handles, int cpu_idx)
{
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_idx, &cpuset);
    int rc = pthread_setaffinity_np(native_handles,
                                    sizeof(cpu_set_t), &cpuset);
    if (rc != 0)
    {
        printf("set cpu affinity error on cpu %d\n", cpu_idx);
    }
    return;
}