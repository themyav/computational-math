cmake_minimum_required(VERSION 3.10)

project(counting_math)

find_package(Python REQUIRED COMPONENTS Interpreter Development)

add_executable(counting_math Lab-2/main.cpp Lab-2/vector_io.cpp Lab-2/methods/binary_division.cpp Lab-2/equations.cpp Lab-2/methods/secant.cpp Lab-2/methods/simple_iteration.cpp Lab-2/methods/newton_system.cpp Lab-2/methods/secant.cpp  Lab-2/gauss.cpp)

target_include_directories(counting_math PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(counting_math PRIVATE ${Python_LIBRARIES})