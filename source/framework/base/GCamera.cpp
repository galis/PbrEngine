//
// Created by galismac on 24/8/2022.
//

#include "GCamera.h"
#include "../../platform/platform.h"

void pbreditor::GCamera::lookAt(glm::vec3 &eye, glm::vec3 &center, glm::vec3 &up) {
    setPosition(eye);
    m_center = center;
    m_up = up;
}

glm::mat4x4 &pbreditor::GCamera::getMatrix() {
    m_view_matrix = glm::lookAt(getPosition(), m_center, m_up);
    return m_view_matrix;
}

pbreditor::GCamera::GCamera() : m_center(0.f, 0.f, 0.f), m_up(0.f, 1.f, 0.f) {
    setName("GCamera" + getId());
}

pbreditor::GCamera::~GCamera() {

}

const glm::vec3 &pbreditor::GCamera::getCenter() const {
    return m_center;
}

const glm::vec3 &pbreditor::GCamera::getUp() const {
    return m_up;
}
