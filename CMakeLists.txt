cmake_minimum_required(VERSION 3.20)
project(Biseccion C)

set(CMAKE_C_STANDARD 11)

add_executable(Biseccion
        intento_biseccion.c)
target_link_libraries(Biseccion m)