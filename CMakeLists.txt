cmake_minimum_required(VERSION 3.0.0)
project(SDL2-RogueLikeClone VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

include(CTest)
enable_testing()

file(GLOB TARGET_SRC "./src/*.cpp" )
add_executable(${PROJECT_NAME} ${TARGET_SRC})

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_image REQUIRED)

include_directories(include)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)
