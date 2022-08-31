//
// Created by galismac on 29/8/2022.
//

#include "GSkyBox.h"
#include "../../platform/platform.h"
#include "../render/GLUtil.h"

const std::vector<std::string> &pbreditor::GSkyBox::getPaths() const {
    return m_paths;
}

void pbreditor::GSkyBox::setPaths(std::vector<std::string> &&paths) {
    m_paths = std::move(paths);
    m_is_update = true;
}

int pbreditor::GSkyBox::load() {
    if (!m_is_update) return RESULT_OK;
    GLUtil::loadCubeMap(m_paths, m_skybox_texture);
    m_is_update = false;
    return RESULT_OK;
}

pbreditor::GSkyBox::GSkyBox(std::vector<std::string> &&paths) : GObject(SKYBOX), m_paths(std::move(paths)), m_is_update(true) {
}

pbreditor::GSkyBox::~GSkyBox() {

}

pbreditor::Texture &pbreditor::GSkyBox::getTexture()  {
    return m_skybox_texture;
}

