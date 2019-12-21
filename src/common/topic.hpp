#ifndef _TOPIC_HPP_
#define _TOPIC_HPP_

#include <mutex>
#include <shared_mutex>

#include "time.hpp"

template <typename T, int CAPACITY>
class Topic
{
public:
    Topic();
    ~Topic();
    void update(T msg);
    void wait(T& msg);
    int copy(T *dst, int len);
private:
    mutable std::shared_mutex mtx;
    std::condition_variable_any refresh;
    T msg_buf[CAPACITY];
    int head = 0;
    int size = 0;
};

template <typename T, int CAPACITY>
Topic<T, CAPACITY>::Topic()
{
    head = 0;
    size = 0;
}

template <typename T, int CAPACITY>
Topic<T, CAPACITY>::~Topic()
{
    ;
}

template <typename T, int CAPACITY>
void Topic<T, CAPACITY>::update(T msg)
{
    std::unique_lock<std::shared_mutex> lock(mtx);
    head = (head + 1) % CAPACITY;
    msg_buf[head] = msg;
    size < CAPACITY ? size += 1 : size = CAPACITY;
    refresh.notify_all();
    return;
}

template <typename T, int CAPACITY>
void Topic<T, CAPACITY>::wait(T& msg)
{
    std::unique_lock<std::shared_mutex> lock(mtx);
    refresh.wait(lock);
    msg = msg_buf[head];
    return;
}

template <typename T, int CAPACITY>
int Topic<T, CAPACITY>::copy(T *dst, int len)
{
    std::unique_lock<std::shared_mutex> lock(mtx);
    int rlen = 0;
    int idx = head;
    len < size ? rlen = len : rlen = size;
    for (int i = 0; i < rlen; i++)
    {
        dst[i] = msg_buf[idx];
        idx = (idx + CAPACITY - 1) % CAPACITY;
    }
    return rlen;
}
#endif