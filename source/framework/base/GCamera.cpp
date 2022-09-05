//
// Created by galismac on 24/8/2022.
//

#include "GCamera.h"
#include "../../platform/platform.h"

void pbreditor::GCamera::lookAt(glm::vec3 &eye, glm::vec3 &center, glm::vec3 &up) {
    setPosition(eye);
    m_cur_front = center;
    m_world_up = up;
}

glm::mat4x4 &pbreditor::GCamera::getViewMatrix() {
    return m_view_matrix;
}

pbreditor::GCamera::GCamera() : GObject(CAMERA), m_world_up(0.f, 1.f, 0.f) {
    setName("GCamera" + getId());
    glm::vec3 defaultRotation(0,-90,0);
    setRotation(defaultRotation);
}

pbreditor::GCamera::~GCamera() {

}

void pbreditor::GCamera::tick() {
    GObject::tick();
    auto& rotation = getRotation();
    if(rotation.x>=89.0f) rotation.x = 89.f;
    if(rotation.x<=-89.0f) rotation.x = -89.f;
    m_cur_front.x = cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
    m_cur_front.y = sin(glm::radians(rotation.x));
    m_cur_front.z = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
    m_cur_front = glm::normalize(m_cur_front);
    // also re-calculate the Right and Up vector
    m_cur_right = glm::normalize(glm::cross(m_cur_front, m_world_up));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_cur_up    = glm::normalize(glm::cross(m_cur_right, m_cur_front));
    m_view_matrix = glm::lookAt(getPosition(), getPosition()+m_cur_front,m_cur_up);
}
