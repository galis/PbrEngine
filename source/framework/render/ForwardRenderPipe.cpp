//
// Created by galismac on 24/8/2022.
//

#include "ForwardRenderPipe.h"

pbreditor::ForwardRenderPipe::ForwardRenderPipe() {

}

pbreditor::ForwardRenderPipe::~ForwardRenderPipe() {

}

void pbreditor::ForwardRenderPipe::render() {
    m_camera_pass.render();
}
