//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_TEXTURE_H
#define PBREDITOR_TEXTURE_H


#include <OpenGL/gl3.h>
#include <string>

namespace pbreditor {

    typedef GLint TextureID;

    class Texture {
    private:
        int m_width;
        int m_height;
        TextureID m_id;
        std::string m_path;
    public:
        Texture(std::string &path);

        ~Texture();

        int load();
    };
}

#endif //PBREDITOR_TEXTURE_H
