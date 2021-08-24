cmake_minimum_required(VERSION 2.8)

project(part3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(words_num words_num.cpp)
add_executable(ltrim_no_req ltrim_no_req.cpp)
add_executable(word_count word_count.cpp)

