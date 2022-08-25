//
// Created by galismac on 24/8/2022.
//

#include <memory>
#include "RenderSystem.h"
#include "ForwardRenderPipe.h"
#include "../../platform/platform.h"

pbreditor::RenderSystem::RenderSystem() : m_render_pipe(std::make_unique<ForwardRenderPipe>()) {
}

pbreditor::RenderSystem::~RenderSystem() {

}

int pbreditor::RenderSystem::init(std::shared_ptr<WindowInfo> winInfo, std::shared_ptr<World> world) {
    m_win_info = winInfo;
    m_world = world;
    m_render_pipe->init();
    return RESULT_OK;
}

int pbreditor::RenderSystem::destroy() {
    m_win_info.reset();
    m_world.reset();
    m_render_pipe->destroy();
    return RESULT_OK;
}

int pbreditor::RenderSystem::tick() {
    m_render_pipe->render(m_win_info.get(), m_world.get());
    return RESULT_OK;
}
