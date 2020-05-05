cmake_minimum_required(VERSION 3.15)
project(LAB3)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(pusaci pusaci.cpp)
add_executable(partibrejker partibrejker.cpp)
target_link_libraries(partibrejker Threads::Threads)
