//
// Created by galismac on 25/8/2022.
//

#include "World.h"
#include "../../platform/platform.h"

pbreditor::World::World() {

}

pbreditor::World::~World() {

}

int pbreditor::World::addModel(glm::vec3 &&pos, std::string &&path) {
    m_models.emplace_back(std::move(path));
    m_models.back().setPosition(pos);
    return RESULT_OK;
}

int pbreditor::World::addLight(LightType type, glm::vec3 &&pos, glm::vec3 &&color) {
    m_lights.emplace_back(type, std::move(color));
    m_lights.back().setPosition(pos);
    return RESULT_OK;
}

int pbreditor::World::removeModel(pbreditor::GObjectId id) {
    return RESULT_OK;
}

int pbreditor::World::removeLight(pbreditor::GObjectId id) {
    return RESULT_OK;
}

int pbreditor::World::setCamera(glm::vec3 &&eye, glm::vec3 &&center, glm::vec3 &&up) {
    m_camera = std::make_shared<GCamera>();
    m_camera->lookAt(eye, center, up);
    return RESULT_OK;
}

std::vector<pbreditor::GModel> &pbreditor::World::getModels() {
    return m_models;
}

std::vector<pbreditor::GLight> &pbreditor::World::getLights() {
    return m_lights;
}

std::shared_ptr<pbreditor::GCamera> pbreditor::World::getCamera() {
    return m_camera;
}

int pbreditor::World::setSkyBox(std::vector<std::string> &&paths) {
    if (!m_skybox) {
        m_skybox = std::make_shared<GSkyBox>(std::move(paths));
    } else {
        m_skybox->setPaths(std::move(paths));
    }
    return 0;
}

std::shared_ptr<pbreditor::GSkyBox> pbreditor::World::getSkyBox() {
    return m_skybox;
}

void pbreditor::World::tick() {
    if (m_skybox) {
        m_skybox->tick();
    }
    if (m_camera) {
        m_camera->tick();
    }
    for (auto &light:m_lights) {
        light.tick();
    }
    for (auto &model:m_models) {
        model.tick();
    }
}

void pbreditor::World::setPerspectiveProj(float fov, float scale, float near, float far) {
    m_proj_matrix = glm::perspective(fov, scale, near, far);
}

void pbreditor::World::setOthoProj(float left, float right, float top, float bottom, float near, float far) {
    m_proj_matrix = glm::ortho(left, right, top, bottom, near, far);
}

glm::mat4x4 &pbreditor::World::getProjMatrix() {
    return m_proj_matrix;
}
