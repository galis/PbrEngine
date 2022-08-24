//
// Created by galismac on 24/8/2022.
//

#include "RenderSystem.h"
#include "ForwardRenderPipe.h"

pbreditor::RenderSystem::RenderSystem() : renderPipe(std::make_unique<ForwardRenderPipe>()) {
}

pbreditor::RenderSystem::~RenderSystem() {

}

int pbreditor::RenderSystem::init() {
    return 0;
}

int pbreditor::RenderSystem::destroy() {
    return 0;
}

int pbreditor::RenderSystem::tick() {
    renderPipe->render();
    return 0;
}
