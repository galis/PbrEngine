//
// Created by galismac on 24/8/2022.
//

#include "GLight.h"

pbreditor::GLight::GLight(pbreditor::LightType type, glm::vec3 &&color) : m_light_type(type), m_light_color(color) {
    setName("GLight" + getId());
}

pbreditor::GLight::~GLight() {

}

std::ostream &pbreditor::operator<<(std::ostream &os, const pbreditor::GLight &light) {
    os << static_cast<const GObject &>(light) << " m_light_color: " << glm::to_string(light.m_light_color)
       << " m_light_type: " << light.m_light_type;
    return os;
}
