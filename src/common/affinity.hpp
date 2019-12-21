#ifndef _AFFINITY_HPP_
#define _AFFINITY_HPP_

#include <pthread.h>

void setAffinity(pthread_t native_handles, int cpu_idx);

#endif