//
// Created by galismac on 24/8/2022.
//

#include "PbrContext.h"

pbreditor::PbrContext::PbrContext() {

}

pbreditor::PbrContext::~PbrContext() {

}

void pbreditor::PbrContext::startSystems() {
    m_world = std::make_shared<World>();
    m_world->addModel({0, 0, 0}, "/Volumes/mac-code/PbrEditor/asset/models/obj/cyborg/cyborg.obj");
//    m_world->addModel({5, 0, 0}, "/Volumes/mac-code/PbrEditor/asset/models/obj/cyborg/cyborg.obj");
    m_world->addLight(POINT, {0, 0, 10}, {1, 1, 1});
    m_world->setCamera({0, 5, 5}, {0, 1, 0}, {0, 1, 0});
    m_world->setSkyBox({
                               "/Volumes/mac-code/PbrEditor/asset/skybox/left.jpg",
                               "/Volumes/mac-code/PbrEditor/asset/skybox/right.jpg",
                               "/Volumes/mac-code/PbrEditor/asset/skybox/top.jpg",
                               "/Volumes/mac-code/PbrEditor/asset/skybox/bottom.jpg",
                               "/Volumes/mac-code/PbrEditor/asset/skybox/back.jpg",
                               "/Volumes/mac-code/PbrEditor/asset/skybox/front.jpg",
                       });
    m_world->setPerspectiveProj(45.f, 1920.f / 1080.f, 0.1f, 100.f);
    m_window_system.init();
    m_render_system.init(m_window_system.getWindowInfo(), m_world);
}

void pbreditor::PbrContext::closeSystems() {
    m_window_system.destroy();
    m_render_system.destroy();
}

void pbreditor::PbrContext::tick() {
    m_window_system.tick();
    m_render_system.tick();
}
