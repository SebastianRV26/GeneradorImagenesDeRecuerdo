cmake_minimum_required(VERSION 3.17)
project(Proyecto1Lenguajes C)

set(CMAKE_C_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system)
add_executable(Proyecto1Lenguajes main.c)

target_link_libraries(Proyecto1Lenguajes sfml-graphics sfml-window sfml-system csfml-graphics csfml-window csfml-system)