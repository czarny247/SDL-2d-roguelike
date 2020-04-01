cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(SdlGame VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SRC_LIST
	src/game/GameLoop.cpp
	src/game/GameLoop.hpp
	src/utils/WindowRaiiWrapper.cpp
	src/utils/WindowRaiiWrapper.hpp
	src/utils/RendererRaiiWrapper.cpp
	src/utils/RendererRaiiWrapper.hpp
)

add_library(${PROJECT_NAME}-lib ${SRC_LIST})
target_link_libraries(${PROJECT_NAME}-lib ${SDL2_LIBRARIES})

add_executable(${PROJECT_NAME}-app ${SRC_LIST} src/main.cpp)
target_link_libraries(${PROJECT_NAME}-app ${SDL2_LIBRARIES} ${PROJECT_NAME}-lib)
