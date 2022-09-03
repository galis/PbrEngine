//
// Created by galismac on 24/8/2022.
//

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include "WindowSystem.h"
#include "GLFW/glfw3.h"

pbreditor::WindowSystem::WindowSystem() : m_is_init(false) {

}

pbreditor::WindowSystem::~WindowSystem() {

}

void pbreditor::WindowSystem::tick() {
    if (glfwWindowShouldClose(m_win_info->window)) return;
    glfwPollEvents();
    //TODO INPUT?
}

void pbreditor::WindowSystem::init() {
    if (m_is_init) return;
    m_is_init = true;
    m_win_info = std::make_shared<WindowInfo>();

    // Setup window
    glfwSetErrorCallback(nullptr);
    if (!glfwInit())
        return;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    m_win_info->width = 1920;
    m_win_info->height = 1080;
    m_win_info->name = "PBR Engine";
    m_win_info->window = glfwCreateWindow(m_win_info->width, m_win_info->height, m_win_info->name.c_str(), NULL, NULL);
    if (!m_win_info->window)
        return;
    glfwMakeContextCurrent(m_win_info->window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return;
    }
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_win_info->window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void pbreditor::WindowSystem::destroy() {
    if (!m_is_init) return;
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_win_info->window);
    glfwTerminate();
    m_win_info->window = nullptr;
    m_win_info->width = 0;
    m_win_info->height = 0;
    m_win_info->name.clear();
}

std::shared_ptr<pbreditor::WindowInfo> pbreditor::WindowSystem::getWindowInfo() {
    return m_win_info;
}
