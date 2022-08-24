//
// Created by galismac on 24/8/2022.
//

#include "GObject.h"

pbreditor::GObject::GObject() : m_id(g_id_alloc++) {

}

pbreditor::GObject::~GObject() {

}

void pbreditor::GObject::tick() {

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

