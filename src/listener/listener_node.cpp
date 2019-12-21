#include "./listener_node.hpp"

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
        printf("thread id: %d time: %ld\n", id, timeBootMs());
        printf("id: %d, %ld\n", id, pos.time_boot_ms);
    }
    
    return;
}