cmake_minimum_required(VERSION 3.17)
project(PbrEditor)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(thirdparty)

if(WIN32)
    set(LIBS glfw3 opengl32 assimp freetype irrKlang)
elseif(UNIX AND NOT APPLE)
    add_library(glad "thirdparty/glad/src/glad.c")
    set(LIBS stb imgui glm glfw assimp GL dl glad)
elseif(APPLE)
    INCLUDE_DIRECTORIES(/System/Library/Frameworks)
    set(LIBS stb imgui glm glfw assimp "-framework OpenGL")
else()
    set(LIBS )
endif(WIN32)

include_directories(thirdparty/glad/include)
file(GLOB_RECURSE src source/*/*.cpp)
add_executable(PbrEditor ${src} )
target_link_libraries(PbrEditor ${LIBS})
