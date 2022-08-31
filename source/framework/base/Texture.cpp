//
// Created by galismac on 24/8/2022.
//

#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "../../platform/platform.h"

pbreditor::Texture::Texture(std::string &&path) : m_path(path), m_id(0), m_width(0), m_height(0), m_type(DIFF) {

}

pbreditor::Texture::Texture() : m_path(""), m_id(0), m_width(0), m_height(0), m_type(DIFF) {

}

pbreditor::Texture::~Texture() {
//    if (m_id != 0) {
//        glDeleteTextures(1, &m_id);
//        m_id = 0;
//        ESLog("%s", "~Texture");
//    }
}

int pbreditor::Texture::load() {
    if (m_path.empty()) return RESULT_ERROR;
    unsigned char *data = stbi_load(m_path.c_str(), &m_width, &m_height, &m_channels, 0);
    if (!data || m_width == 0) goto finish;
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    if (m_channels == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    } else if (m_channels == 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    } else if (m_channels == 1) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMIANCE, m_width, m_height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glBindTexture(GL_TEXTURE_2D, 0);
    finish:
    if (data) {
        stbi_image_free(data);
    }
    return RESULT_OK;
}

int pbreditor::Texture::getWidth() const {
    return m_width;
}

int pbreditor::Texture::getHeight() const {
    return m_height;
}

int pbreditor::Texture::getChannels() const {
    return m_channels;
}

pbreditor::TextureID pbreditor::Texture::getId() const {
    return m_id;
}

void pbreditor::Texture::setId(pbreditor::TextureID id) {
    m_id = id;
}

const std::string &pbreditor::Texture::getPath() const {
    return m_path;
}

void pbreditor::Texture::setPath(const std::string &path) {
    m_path = path;
}



