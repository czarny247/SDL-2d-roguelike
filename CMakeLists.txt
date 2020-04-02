cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(SdlGame VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src)

set(SRC_LIST
	src/game/GameLoop.cpp
	src/game/GameLoop.hpp
	src/utils/WindowRaiiWrapper.cpp
	src/utils/WindowRaiiWrapper.hpp
	src/utils/RendererRaiiWrapper.cpp
	src/utils/RendererRaiiWrapper.hpp
	src/graphics/TextureManager.cpp
	src/graphics/TextureManager.hpp
)

add_library(${PROJECT_NAME}-lib ${SRC_LIST})
target_link_libraries(${PROJECT_NAME}-lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

add_executable(${PROJECT_NAME}-app ${SRC_LIST} src/main.cpp)
target_link_libraries(${PROJECT_NAME}-app ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${PROJECT_NAME}-lib)
