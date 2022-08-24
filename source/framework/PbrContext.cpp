//
// Created by galismac on 24/8/2022.
//

#include "PbrContext.h"

pbreditor::PbrContext::PbrContext() {

}

pbreditor::PbrContext::~PbrContext() {

}

void pbreditor::PbrContext::startSystems() {
    uiSystem.init();
}

void pbreditor::PbrContext::closeSystems() {
    uiSystem.destroy();
}
