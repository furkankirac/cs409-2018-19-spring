cmake_minimum_required(VERSION 2.8)

project(advcpp)

SET(CMAKE_CXX_FLAGS "-std=c++17")

add_executable(app1 "app1.cpp")
add_executable(app2 "app2.cpp")
add_executable(app3 "app3.cpp")
add_executable(app4 "app4.cpp")
add_executable(app5 "app5.cpp")
add_executable(app6 "app6.cpp")
add_executable(app7 "app7.cpp" "Matrix.h")
add_executable(app8 "app8.cpp" "Matrix.h")
