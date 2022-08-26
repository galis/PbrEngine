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
