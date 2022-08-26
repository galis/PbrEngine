//
// Created by galismac on 24/8/2022.
//

#include "GCamera.h"
#include "../../platform/platform.h"

void pbreditor::GCamera::lookAt(glm::vec3 &eye, glm::vec3 &center, glm::vec3 &up) {
    m_eye = eye;
    m_center = center;
    m_up = up;
    m_view_matrix = glm::perspective(45.f, 1920.f / 1080.f, 0.1f, 100.f) * glm::lookAt(m_eye, m_center, m_up);
    auto imat = glm::identity<glm::mat4x4>();
    ESLog("%s", glm::to_string(m_view_matrix).c_str());
    ESLog("%s", glm::to_string(imat).c_str());
}

glm::mat4x4 &pbreditor::GCamera::getMatrix() {
    return m_view_matrix;
}

pbreditor::GCamera::GCamera() : m_eye(0.f, 0.f, 0.f), m_center(0.f, 0.f, 0.f), m_up(0.f, 1.f, 0.f) {

}

pbreditor::GCamera::~GCamera() {

}

const glm::vec3 &pbreditor::GCamera::getEye() const {
    return m_eye;
}

const glm::vec3 &pbreditor::GCamera::getCenter() const {
    return m_center;
}

const glm::vec3 &pbreditor::GCamera::getUp() const {
    return m_up;
}
