//
// Created by galismac on 24/8/2022.
//

#include "PbrContext.h"

pbreditor::PbrContext::PbrContext() {

}

pbreditor::PbrContext::~PbrContext() {

}

void pbreditor::PbrContext::startSystems() {
    m_world.addModel({0, 0, 0}, "/Volumes/mac-code/PbrEditor/asset/models/obj/cyborg/cyborg.obj");
    m_world.addLight(POINT, {0, 0, 1}, {1, 1, 1});
    m_uiSystem.init();
    m_renderSystem.init();
}

void pbreditor::PbrContext::closeSystems() {
    m_uiSystem.destroy();
    m_renderSystem.destroy();
}
