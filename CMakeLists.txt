
cmake_minimum_required(VERSION 3.0.0)

project(tictactoe VERSION 0.1.0)

set(SOURCE_FILES
    src/engine.cc
    src/main.cc
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include_directories(include)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)

