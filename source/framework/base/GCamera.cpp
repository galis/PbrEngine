//
// Created by galismac on 24/8/2022.
//

#include "GCamera.h"

void pbreditor::GCamera::lookAt(glm::vec3 &eye, glm::vec3 &center, glm::vec3 &up) {
    m_eye = eye;
    m_center = center;
    m_up = up;
}

glm::mat4x4 &pbreditor::GCamera::getMatrix() {
    return m_view_matrix;
}

pbreditor::GCamera::GCamera():m_eye(0.f,0.f,0.f),m_center(0.f,0.f,0.f),m_up(0.f,0.f,1.f) {

}

pbreditor::GCamera::~GCamera() {

}
