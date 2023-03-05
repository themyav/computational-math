cmake_minimum_required(VERSION 3.24)
project(counting_math)

set(CMAKE_CXX_STANDARD 17)


add_executable(counting_math Lab-2/main.cpp Lab-2/vector_io.cpp Lab-2/methods/binary_division.cpp Lab-2/equations.cpp Lab-2/methods/secant.cpp Lab-2/methods/simple_iteration.cpp Lab-2/methods/newton_system.cpp Lab-2/methods/secant.cpp)
