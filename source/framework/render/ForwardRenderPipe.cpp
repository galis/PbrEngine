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
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mainCameraPass.render(winInfo, world);
    glfwSwapBuffers(winInfo->window);
    return RESULT_OK;
}

int pbreditor::ForwardRenderPipe::init() {
    mainCameraPass.init();
    return RenderPipe::init();
}

int pbreditor::ForwardRenderPipe::destroy() {
    mainCameraPass.destroy();
    return RenderPipe::destroy();
}

