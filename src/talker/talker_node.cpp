#include "./talker_node.hpp"
#include <thread>
#include <mutex>
#include <chrono>

void talkerLoop(int id)
{
    float x_m = 0, y_m = 0, z_m = 0;
    int64_t time_boot_ms = 0;
    while (true)
    {
        printf("thread id: %d time: %ld CPU: %d\n", id, timeBootMs(), sched_getcpu());
        time_boot_ms = timeBootMs();
        Position pos = {x_m, y_m, z_m, time_boot_ms};
        position_topic.update(pos);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return;
}