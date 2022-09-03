//
// Created by galismac on 29/8/2022.
//

#ifndef PBREDITOR_GSKYBOX_H
#define PBREDITOR_GSKYBOX_H

#include "GObject.h"
#include "Texture.h"
#include <vector>

namespace pbreditor {
    class GSkyBox : public GObject {
    private:
        std::vector<std::string> m_paths;
        bool m_is_update;
        Texture m_skybox_texture;

    public:
        explicit GSkyBox(std::vector<std::string> &&paths);

        ~GSkyBox() override;

        const std::vector<std::string> &getPaths() const;

        void setPaths(std::vector<std::string> &&paths);

        int load();

        Texture &getTexture();
    };
}


#endif //PBREDITOR_GSKYBOX_H
