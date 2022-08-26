//
// Created by galismac on 24/8/2022.
//

#include "Transform.h"

void pbreditor::Transform::setPositionX(float x) {
    m_position.x = x;
}

void pbreditor::Transform::setPositionY(float y) {
    m_position.y = y;
}

void pbreditor::Transform::setPositionZ(float z) {
    m_position.z = z;
}

void pbreditor::Transform::setPosition(glm::vec3 &position) {
    m_position = position;
}

void pbreditor::Transform::setScaleX(float x) {
    m_scale.x = x;
}

void pbreditor::Transform::setScaleY(float y) {
    m_scale.y = y;
}

void pbreditor::Transform::setScaleZ(float z) {
    m_scale.z = z;
}

void pbreditor::Transform::setScale(glm::vec3 &scale) {
    m_scale = scale;
}

void pbreditor::Transform::setRotationX(float x) {
    m_rotation.x = x;
}

void pbreditor::Transform::setRotationY(float y) {
    m_rotation.y = y;
}

void pbreditor::Transform::setRotationZ(float z) {
    m_rotation.z = z;
}

void pbreditor::Transform::setRotation(glm::vec3 &rotation) {
    m_rotation = rotation;
}

glm::vec3 &pbreditor::Transform::getPosition() {
    return m_position;
}

glm::vec3 &pbreditor::Transform::getRotation() {
    return m_rotation;
}

glm::vec3 &pbreditor::Transform::getScale() {
    return m_scale;
}

pbreditor::Transform::Transform() : m_position(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f), m_rotation(0.f, 0.f, 0.f) {

}

pbreditor::Transform::~Transform() {

}

std::ostream &pbreditor::operator<<(std::ostream &os, const pbreditor::Transform &transform) {
    os << "position: " << glm::to_string(transform.m_position)
       << " rotation: " << glm::to_string(transform.m_rotation)
       << " scale: " << glm::to_string(transform.m_scale)
       << std::endl;
    return os;
}
