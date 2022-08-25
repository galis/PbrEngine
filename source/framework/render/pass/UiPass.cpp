//
// Created by galismac on 25/8/2022.
//

#include "UiPass.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include "../../../platform/platform.h"

pbreditor::UiPass::UiPass() {

}

pbreditor::UiPass::~UiPass() {

}

int pbreditor::UiPass::render(const WindowInfo *winInfo) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    //创建主菜单
    ImGui::BeginMainMenuBar();
    ImGui::Button("File");
    ImGui::Button("Edit");
    ImGui::Button("Help");
    ImGui::EndMainMenuBar();

    ImGui::Begin("Debug View");
    ImGui::Text("transform");
    ImGui::Text("position");
    ImGui::Text("rotation");
    ImGui::Text("scale");
    ImGui::End();

    // Rendering
    ImGui::Render();
    glViewport(0, 0, winInfo->width, winInfo->height);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return RESULT_OK;
}
