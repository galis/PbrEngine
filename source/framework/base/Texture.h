//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_TEXTURE_H
#define PBREDITOR_TEXTURE_H


#ifdef __APPLE__
#include <OpenGL/gl.h3>
#else
#include <GL/glut.h>
#endif
#include <string>

namespace pbreditor {

    typedef GLuint TextureID;

    class Texture {
    private:
        int m_width;
        int m_height;
        int m_channels;
        TextureID m_id;
        std::string m_path;
    public:

        explicit Texture(std::string &&path);

        ~Texture();

        int load();

        int getWidth() const;

        int getHeight() const;

        int getChannels() const;

        TextureID getId() const;

        const std::string &getPath() const;

    };
}

#endif //PBREDITOR_TEXTURE_H
