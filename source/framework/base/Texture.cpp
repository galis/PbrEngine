//
// Created by galismac on 24/8/2022.
//

#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "../../platform/platform.h"

pbreditor::Texture::Texture(std::string &&path) : m_path(path), m_id(0), m_width(0), m_height(0) {

}

pbreditor::Texture::~Texture() {
    if (m_id != 0) {
        glDeleteTextures(1, &m_id);
        m_id = 0;
    }
}

int pbreditor::Texture::load() {
    if (m_path.empty()) return RESULT_ERROR;
    unsigned char *data = stbi_load(m_path.c_str(), &m_width, &m_height, &m_channels, 0);
    if (!data || m_width == 0) goto finish;
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_INT, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glBindTexture(GL_TEXTURE_2D, 0);
    finish:
    if (data) {
        stbi_image_free(data);
    }
    return RESULT_OK;
}

