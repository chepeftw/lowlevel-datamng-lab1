cmake_minimum_required(VERSION 3.15)
project(ex3 C)

set(CMAKE_C_STANDARD 99)

add_executable(ex3_fork fork/fork.c)

add_executable(ex3_shm_p shared_memory/producer.c)
add_executable(ex3_shm_c shared_memory/consumer.c)

add_executable(ex3_pipes_s pipes/simple.c)
add_executable(ex3_pipes_p pipes/processes.c)
add_executable(ex3_pipes_nrf pipes/named_readfirst.c)
add_executable(ex3_pipes_nwf pipes/named_writefirst.c)