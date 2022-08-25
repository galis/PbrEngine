//
// Created by galismac on 24/8/2022.
//

#include <unistd.h>
#include "PbrEngine.h"
#include "../platform/platform.h"

pbreditor::PbrEngine::PbrEngine() {
}

bool pbreditor::PbrEngine::init() {
    m_context = std::make_shared<PbrContext>();
    m_context->startSystems();
    return RESULT_OK;
}

bool pbreditor::PbrEngine::destroy() {
    m_context->closeSystems();
    m_context.reset();
    return RESULT_OK;
}

void pbreditor::PbrEngine::run() {
    float sum = 0;
    while (sum < 100000.0) {
        m_context->tick();
        sum += 0.03;
    }
}

pbreditor::PbrEngine::~PbrEngine() {

}
