//
// Created by galismac on 25/8/2022.
//

#ifndef PBREDITOR_WORLD_H
#define PBREDITOR_WORLD_H

#include "GModel.h"
#include "GLight.h"
#include "GCamera.h"
#include "GSkyBox.h"
#include <memory>
#include <vector>

namespace pbreditor {

    class World {
    private:
        std::vector<GModel> m_models;
        std::vector<GLight> m_lights;
        std::shared_ptr<GCamera> m_camera;
        std::shared_ptr<GSkyBox> m_skybox;
        glm::mat4x4 m_proj_matrix;
    public:
        World();

        ~World();

        int addModel(glm::vec3 &&pos, std::string &&path);

        int addLight(LightType type, glm::vec3 &&pos, glm::vec3 &&color);

        int removeModel(GObjectId id);

        int removeLight(GObjectId id);

        int setSkyBox(std::vector<std::string> &&paths);

        int setCamera(glm::vec3 &&eye, glm::vec3 &&center, glm::vec3 &&up);

        void setPerspectiveProj(float fov, float scale, float near, float far);

        void setOthoProj(float left, float right, float top, float bottom, float near, float far);

        glm::mat4x4 &getProjMatrix();

        void tick();

        std::vector<GModel> &getModels();

        std::vector<GLight> &getLights();

        std::shared_ptr<GCamera> getCamera();

        std::shared_ptr<GSkyBox> getSkyBox();
    };

}

#endif //PBREDITOR_WORLD_H
