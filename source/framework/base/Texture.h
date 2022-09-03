//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_TEXTURE_H
#define PBREDITOR_TEXTURE_H


#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif
#include <string>

namespace pbreditor {

    typedef GLuint TextureID;
    enum TextureType {
        DIFF,
        NORMAL,
        SPECULAR,
        CUBE,
    };

    class Texture {
    private:
        int m_width;
        int m_height;
        int m_channels;
        TextureID m_id;
        std::string m_path;
        TextureType m_type;
    public:

        explicit Texture(std::string &&path);

        Texture();

        ~Texture();

        int load();

        int getWidth() const;

        int getHeight() const;

        int getChannels() const;

        TextureID getId() const;

        void setId(TextureID id);

        const std::string &getPath() const;

        void setPath(const std::string &mPath);

    };
}

#endif //PBREDITOR_TEXTURE_H
