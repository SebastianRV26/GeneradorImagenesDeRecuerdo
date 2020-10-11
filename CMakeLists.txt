cmake_minimum_required(VERSION 3.17)
project(Proyecto1Lenguajes C)

set(CMAKE_C_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics system)
add_executable(Proyecto1Lenguajes main.c)

target_link_libraries(Proyecto1Lenguajes sfml-graphics sfml-system csfml-graphics csfml-system)