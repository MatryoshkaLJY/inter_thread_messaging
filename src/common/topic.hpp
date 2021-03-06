#ifndef _TOPIC_HPP_
#define _TOPIC_HPP_

#include <mutex>
#include <condition_variable>

#include "time.hpp"

template <typename T, int CAPACITY>
class Topic
{
public:
    Topic();
    ~Topic();
    void update(T msg);
    void updateHandle(T& msg) const;
    int copy(T *dst, int len) const;
private:
    mutable std::mutex mtx;
    mutable std::condition_variable refresh;
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
    std::unique_lock<std::mutex> lock(mtx);
    head = (head + 1) % CAPACITY;
    msg_buf[head] = msg;
    size < CAPACITY ? size += 1 : size = CAPACITY;
    lock.unlock();
    refresh.notify_all();
    return;
}

template <typename T, int CAPACITY>
void Topic<T, CAPACITY>::updateHandle(T& msg) const
{
    std::unique_lock<std::mutex> lock(mtx);
    refresh.wait(lock);
    msg = msg_buf[head];
    return;
}

template <typename T, int CAPACITY>
int Topic<T, CAPACITY>::copy(T *dst, int len) const
{
    std::unique_lock<std::mutex> lock(mtx);
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