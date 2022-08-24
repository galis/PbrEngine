set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

file(GLOB IMGUI_SRC CONFIGURE_DEPENDS "${IMGUI_DIR}/*.cpp")
file(GLOB IMGUI_IMPL CONFIGURE_DEPENDS
        "${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
        "${IMGUI_DIR}/backends/imgui_impl_glfw.h"
        "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
        "${IMGUI_DIR}/backends/imgui_impl_opengl3.h")
add_library(imgui STATIC ${IMGUI_SRC} ${IMGUI_IMPL})
target_include_directories(imgui PUBLIC $<BUILD_INTERFACE:${IMGUI_DIR}>)
target_link_libraries(imgui PUBLIC glfw )