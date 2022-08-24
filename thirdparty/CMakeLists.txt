message("start build thirdparty>>>>>>>")

#set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

if (NOT TARGET imgui)
    include(imgui.cmake)
endif ()

if (NOT TARGET stb)
    include(stb.cmake)
    #    set_target_properties(stb PROPERTIES FOLDER stb)
endif ()

if (NOT TARGET glm)
    option(BUILD_STATIC_LIBS "" ON)
    option(BUILD_TESTING "" OFF)
    option(GLM_TEST_ENABLE "" OFF)
    add_subdirectory(glm)
    set_target_properties(glm_static PROPERTIES FOLDER glm)
endif ()

if (NOT TARGET assimp)
    add_subdirectory(assimp)
    set_target_properties(assimp PROPERTIES FOLDER assimp)
endif ()

if (NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
    set_target_properties(glfw PROPERTIES FOLDER glfw)
    set_target_properties(update_mappings PROPERTIES FOLDER /glfw)
endif ()
message("finish build thirdpart<<<<<<<")

