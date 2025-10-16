cmake_minimum_required(VERSION 3.30)
project(ACPCTeamzone)

set(CMAKE_CXX_STANDARD 20)

add_executable(ACPCTeamzone
        arena_exercises/greedy/ex1/serial.cpp
        arena_exercises/greedy/ex2/hassany.cpp
        arena_exercises/greedy/ex3/job_sequencing.cpp)
