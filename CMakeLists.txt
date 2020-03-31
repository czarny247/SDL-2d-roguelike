cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(SDL_TEST VERSION 0.1.0 LANGUAGES CXX C)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(sdlTestExec src/main.cpp)

target_link_libraries(sdlTestExec ${SDL2_LIBRARIES})