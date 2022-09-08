cmake_minimum_required(VERSION 3.8)

project(HELLO_OpenGL) 

include_directories(glfw-3.3.7.bin.MACOS/include glad/include)

link_directories(glfw-3.3.7.bin.MACOS/lib-arm64)

ADD_EXECUTABLE(${PROJECT_NAME} OpenGL_Test/main.cpp glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} libglfw.3.a)