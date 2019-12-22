#include <thread>
#include "talker/talker_node.hpp"
#include "listener/listener_node.hpp"
#include "common/affinity.hpp"
#include <iostream>

int main(void)
{
    unsigned num_cpus = std::thread::hardware_concurrency();
    printf("%d cpu available\n", num_cpus);
    std::thread talker_node(talkerLoop, 0);
    std::thread listener_node_1(listenerLoop, 1);
    std::thread listener_node_2(listenerLoop, 2);
    std::thread listener_node_3(listenerLoop, 3);

    setAffinity(talker_node.native_handle(), 0);
    setAffinity(listener_node_1.native_handle(), 1);
    setAffinity(listener_node_2.native_handle(), 2);
    setAffinity(listener_node_3.native_handle(), 3);
    talker_node.join();
    listener_node_1.join();
    listener_node_2.join();
    listener_node_3.join();
    return 0;
}