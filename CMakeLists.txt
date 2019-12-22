cmake_minimum_required(VERSION 2.8)
project(itm_demo)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -Wno-psabi")
set(PLATFORM_LIBS pthread ${CMAKE_DL_LIBS})

include_directories(./src )

aux_source_directory(./src/ MAIN_SRC)
aux_source_directory(./src/common COMMON_SRC)
aux_source_directory(./src/talker TALKER_SRC)
aux_source_directory(./src/listener LISTENER_SRC)
aux_source_directory(./src/msg MSG_SRC)

add_executable(demo
               ${MAIN_SRC}
               ${TALKER_SRC}
               ${LISTENER_SRC}
               ${MSG_SRC}
               ${COMMON_SRC}
)

target_link_libraries(demo
                      ${PLATFORM_LIBS}
)
