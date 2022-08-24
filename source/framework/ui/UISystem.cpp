//
// Created by galismac on 24/8/2022.
//

#include "UISystem.h"
#include "Imgui.h"

pbreditor::UISystem::UISystem() : m_is_init(false) {

}

pbreditor::UISystem::~UISystem() {

}

void pbreditor::UISystem::tick() {

}

void pbreditor::UISystem::init() {
    if (m_is_init) return;
    m_is_init = true;

}

void pbreditor::UISystem::destroy() {

}
