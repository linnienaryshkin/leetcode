cmake_minimum_required(VERSION 3.20)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all problem files
file(GLOB PROBLEMS "problems/*.cpp")

# Create executable for each problem
foreach(problem ${PROBLEMS})
    get_filename_component(problem_name ${problem} NAME_WE)
    add_executable(${problem_name} ${problem})
endforeach()