cmake_minimum_required(VERSION 3.17)
project(PbrEditor)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE src source/*/*.cpp)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_executable(PbrEditor source/editor/editor_main.cpp ${src} )
target_link_libraries(PbrEditor assimp opencv_core opencv_highgui opencv_imgcodecs opencv_imgproc)