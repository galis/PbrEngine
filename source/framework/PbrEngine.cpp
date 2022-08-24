//
// Created by galismac on 24/8/2022.
//

#include "PbrEngine.h"

pbreditor::PbrEngine::PbrEngine() {
}

bool pbreditor::PbrEngine::init() {
    m_context = std::make_shared<PbrContext>();
    m_context->startSystems();
    return false;
}

bool pbreditor::PbrEngine::destroy() {
    m_context.reset();
    return false;
}

void pbreditor::PbrEngine::run() {

}

pbreditor::PbrEngine::~PbrEngine() {

}
