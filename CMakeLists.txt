cmake_minimum_required(VERSION 3.8)
project(Ray_Tracer)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES
        "src/*.h"
        "src/*.cpp")

add_executable(Ray_Tracer ${SOURCE_FILES})