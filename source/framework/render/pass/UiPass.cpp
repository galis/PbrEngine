//
// Created by galismac on 25/8/2022.
//

#include "UiPass.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include "../../../platform/platform.h"

pbreditor::UiPass::UiPass() : m_current_gobject(nullptr) {

}

pbreditor::UiPass::~UiPass() {

}

int pbreditor::UiPass::render(const WindowInfo *winInfo, World *world) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    //创建主菜单
    ImGui::BeginMainMenuBar();
    ImGui::Button("File");
    ImGui::Button("Edit");
    ImGui::Button("Help");
    ImGui::EndMainMenuBar();

    ImGui::Begin("GObjects of world");
    if (ImGui::Selectable(world->getCamera()->getName().c_str(), m_current_gobject == world->getCamera().get())) {
        m_current_gobject = world->getCamera().get();
    }
    for (GLight &light:world->getLights()) {
        if (ImGui::Selectable(light.getName().c_str(), m_current_gobject == &light)) {
            m_current_gobject = &light;
        }
    }
    for (GModel &model:world->getModels()) {
        if (ImGui::Selectable(model.getName().c_str(), m_current_gobject == &model)) {
            m_current_gobject = &model;
        }

    }
    ImGui::End();

    ImGui::Begin("GObject attributes");
    if (m_current_gobject) {
        ImGui::InputFloat("px", &m_current_gobject->getPosition()[0], 0.2f, 2.0f, "%.3f");
        ImGui::InputFloat("py", &m_current_gobject->getPosition()[1], 0.2f, 2.0f, "%.3f");
        ImGui::InputFloat("pz", &m_current_gobject->getPosition()[2], 0.2f, 2.0f, "%.3f");
        ImGui::InputFloat("rx", &m_current_gobject->getRotation()[0], 5.f, 10.0f, "%.3f");
        ImGui::InputFloat("ry", &m_current_gobject->getRotation()[1], 5.f, 10.0f, "%.3f");
        ImGui::InputFloat("rz", &m_current_gobject->getRotation()[2], 5.f, 10.0f, "%.3f");
        ImGui::InputFloat("sx", &m_current_gobject->getScale()[0], 0.2f, 2.0f, "%.3f");
        ImGui::InputFloat("sy", &m_current_gobject->getScale()[1], 0.2f, 2.0f, "%.3f");
        ImGui::InputFloat("sz", &m_current_gobject->getScale()[2], 0.2f, 2.0f, "%.3f");

        if (m_current_gobject->getType() == LIGHT) {
            ImGui::ColorEdit3("light color ", &((GLight *) m_current_gobject)->getLightColor()[0]);
        }

        //过滤rotation数据
        m_current_gobject->getRotation()[0] = int(m_current_gobject->getRotation()[0]) % 360;
        m_current_gobject->getRotation()[1] = int(m_current_gobject->getRotation()[1]) % 360;
        m_current_gobject->getRotation()[2] = int(m_current_gobject->getRotation()[2]) % 360;


        ImGui::Text("position:%.3f,%.3f,%.3f", m_current_gobject->getPosition()[0], m_current_gobject->getPosition()[1],
                    m_current_gobject->getPosition()[2]);
        ImGui::Text("rotation:%.3f,%.3f,%.3f", m_current_gobject->getRotation()[0], m_current_gobject->getRotation()[1],
                    m_current_gobject->getRotation()[2]);
        ImGui::Text("scale:%.3f,%.3f,%.3f", m_current_gobject->getScale()[0], m_current_gobject->getScale()[1],
                    m_current_gobject->getScale()[2]);
    }
    ImGui::End();

    ImGui::ShowDemoWindow();

    // Rendering
    ImGui::Render();
    glViewport(0, 0, winInfo->width, winInfo->height);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return RESULT_OK;
}

