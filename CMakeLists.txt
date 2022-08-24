cmake_minimum_required(VERSION 3.17)
project(PbrEditor)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(thirdparty)

file(GLOB_RECURSE src source/*/*.cpp)

add_executable(PbrEditor ${src})
target_link_libraries(PbrEditor imgui glm glfw "-framework OpenGL")
