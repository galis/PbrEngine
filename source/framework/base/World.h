//
// Created by galismac on 25/8/2022.
//

#ifndef PBREDITOR_WORLD_H
#define PBREDITOR_WORLD_H

#include "GModel.h"
#include "GLight.h"
#include "GCamera.h"
#include <memory>
#include <vector>

namespace pbreditor {

    class World {
    private:
        std::vector<GModel> m_models;
        std::vector<GLight> m_lights;
        std::shared_ptr<GCamera> m_camera;
    public:
        World();

        ~World();

        int addModel(glm::vec3 &&pos, std::string &&path);

        int addLight(LightType type, glm::vec3 &&pos, glm::vec3 &&color);

        int removeModel(GObjectId id);

        int removeLight(GObjectId id);

        int setCamera(glm::vec3 &&eye, glm::vec3 &&center, glm::vec3 &&up);

        std::vector<GModel> &getModels();

        std::vector<GLight> &getLights();

        std::shared_ptr<GCamera> getCamera();
    };

}

#endif //PBREDITOR_WORLD_H
