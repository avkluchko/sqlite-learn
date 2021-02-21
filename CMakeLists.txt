cmake_minimum_required(VERSION 3.17)
project(SQLiteLearn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror")

add_subdirectory(libs/googletest)

add_subdirectory(src)
add_subdirectory(tests)

