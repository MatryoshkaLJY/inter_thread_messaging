#include "./listener_node.hpp"
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
void listenerLoop( int id )
{
    /* non-blocking */
    // Position pos_buf[5];
    // while (true)
    // {
    //     printf("thread id: %d time: %ld\n", id, timeBootMs());
    //     int size = position_topic.copy(pos_buf, sizeof(pos_buf) / sizeof(Position));
    //     if (size != 0)
    //     {
    //         for( int i=0; i < size; i++)
    //             printf("id: %d, size: %d, %d: %ld\n", id, size, i, pos_buf[i].time_boot_ms);
    //     }
    //     std::this_thread::sleep_for(std::chrono::milliseconds(300));
    // }

    /* blocking */
    Position pos;
    while (true)
    {
        position_topic.wait(pos);
        printf("thread id: %d time: %ld CPU: %d\n", id, timeBootMs(), sched_getcpu());
        //printf("thread id: %d awake! pos.time_boot_ms=%ld\n", id, pos.time_boot_ms);
    }
    return;
}