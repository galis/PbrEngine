//
// Created by galismac on 24/8/2022.
//

#include "ForwardRenderPipe.h"
#include "../../platform/platform.h"

pbreditor::ForwardRenderPipe::ForwardRenderPipe() {

}

pbreditor::ForwardRenderPipe::~ForwardRenderPipe() {

}

int pbreditor::ForwardRenderPipe::render(const WindowInfo *winInfo, World *world) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_camera_pass.render(winInfo, world);
    m_ui_pass.render(winInfo, world);
    glfwSwapBuffers(winInfo->window);
    return RESULT_OK;
}

int pbreditor::ForwardRenderPipe::init() {
    m_camera_pass.init();
    m_ui_pass.init();
    return RenderPipe::init();
}

int pbreditor::ForwardRenderPipe::destroy() {
    m_camera_pass.destroy();
    m_ui_pass.destroy();
    return RenderPipe::destroy();
}

