//
// Created by galismac on 24/8/2022.
//

#include "GObject.h"

pbreditor::GObject::GObject(GObjectType type) : m_id(g_id_alloc++), m_name("Default"), m_type(type) {

}

pbreditor::GObject::~GObject() {

}

pbreditor::GObjectId pbreditor::GObject::getId() const {
    return m_id;
}

void pbreditor::GObject::setId(int id) {
    m_id = id;
}

const std::string &pbreditor::GObject::getName() const {
    return m_name;
}

void pbreditor::GObject::setName(const std::string &name) {
    m_name = name;
}

std::ostream &pbreditor::operator<<(std::ostream &os, const pbreditor::GObject &object) {
    os << static_cast<const Transform &>(object) << " m_id: " << object.m_id << " m_name: " << object.m_name;
    return os;
}

pbreditor::GObjectType pbreditor::GObject::getType() const {
    return m_type;
}

void pbreditor::GObject::setType(pbreditor::GObjectType mType) {
    m_type = mType;
}

glm::mat4x4 &pbreditor::GObject::getMatrix() {
    return m_matrix;
}

void pbreditor::GObject::tick() {
    glm::mat4x4 identyMatrix = glm::identity<glm::mat4x4>();
    auto tMat = glm::translate(glm::identity<glm::mat4>(),getPosition());
    auto rMat = glm::rotate(identyMatrix, glm::radians(getRotation().z), {0, 0, 1}) *
               glm::rotate(identyMatrix, glm::radians(getRotation().y), {0, 1, 0}) *
               glm::rotate(identyMatrix, glm::radians(getRotation().x), {1, 0, 0});
    m_matrix = tMat*rMat;
}


