#ifndef _LISTENER_NODE_HPP_
#define _LISTENER_NODE_HPP_

#include "common/topic.hpp"
#include "msg/struct.hpp"

extern Topic<Position, 10> position_topic;
extern Topic<Velocity, 10> velocity_topic;

void listenerLoop( int id );

#endif