cmake_minimum_required(VERSION 3.0.0)
project(SDL2-RogueLikeClone VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

file(GLOB TARGET_SRC "./src/*.cpp" )
add_executable(${PROJECT_NAME} ${TARGET_SRC})

include_directories(include assets)
set(asset_src "${CMAKE_SOURCE_DIR}/assets")
set(asset_dst "${CMAKE_CURRENT_BINARY_DIR}/assets") 
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${asset_src} ${asset_dst} 
    DEPENDS ${asset_dst}
    COMMENT "symbolic link resources folder from ${asset_src} => ${asset_dst}"
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find and include SDL2
find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

# Find and include SDL2_image
find_package(SDL2_image REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)

# # Find and link SDL2_gfx
# find_package(SDL2_gfx REQUIRED)
# target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_GFX_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} ${SDL2_GFX_LIBRARIES})
