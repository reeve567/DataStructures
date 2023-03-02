cmake_minimum_required(VERSION 3.24)
project(data_structures)

set(CMAKE_CXX_STANDARD 23)

add_executable(data_structures Queues/main.cpp Queues/DynamicQueue.cpp Queues/DynamicQueuesTest.cpp)