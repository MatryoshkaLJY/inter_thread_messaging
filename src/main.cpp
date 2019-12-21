#include <thread>
#include <talker/talker_node.hpp>
#include <listener/listener_node.hpp>

int main(void)
{
    std::thread talker_node(talkerLoop, 0);
    std::thread listener_node_1(listenerLoop, 1);
    std::thread listener_node_2(listenerLoop, 2);
    talker_node.join();
    listener_node_1.join();
    listener_node_2.join();
    return 0;
}