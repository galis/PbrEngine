//
// Created by galismac on 24/8/2022.
//

#include "Texture.h"

pbreditor::Texture::Texture(std::string &path) : m_path(path), m_id(0), m_width(0), m_height(0) {

}

pbreditor::Texture::~Texture() {

}

int pbreditor::Texture::load() {
    return 0;
}
