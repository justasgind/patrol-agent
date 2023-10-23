cmake_minimum_required(VERSION 3.26)
project(patrol_agent)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(patrol_agent src/main.cpp
        src/Agent.cpp
        include/Agent.h
        src/Engine.cpp
        include/Engine.h)
target_link_libraries(patrol_agent ${CURSES_LIBRARY})
