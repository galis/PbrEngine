//
// Created by galismac on 29/8/2022.
//

#include "MainCameraPass.h"

pbreditor::MainCameraPass::MainCameraPass() {

}

pbreditor::MainCameraPass::~MainCameraPass() {

}

int pbreditor::MainCameraPass::init() {
    m_bling_phone_pass.init();
    m_skybox_pass.init();
    m_ui_pass.init();
    return RenderPass::init();
}

int pbreditor::MainCameraPass::destroy() {
    m_bling_phone_pass.destroy();
    m_skybox_pass.destroy();
    m_ui_pass.destroy();
    return RenderPass::destroy();
}

int pbreditor::MainCameraPass::render(const pbreditor::WindowInfo *winInfo, pbreditor::World *world) {
    m_bling_phone_pass.render(winInfo, world);
//    m_skybox_pass.render(winInfo,world);
    m_ui_pass.render(winInfo,world);
    return RenderPass::render(winInfo, world);
}
