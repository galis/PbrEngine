//
// Created by galismac on 24/8/2022.
//

#pragma once

#include "GObject.h"

namespace pbreditor {

    class GCamera : public GObject {
    private:
        glm::vec3 m_world_up;
        glm::vec3 m_cur_front;
        glm::vec3 m_cur_up;
        glm::vec3 m_cur_right;
        glm::mat4x4 m_view_matrix;
    public:

        GCamera();

        ~GCamera();

        void lookAt(glm::vec3 &eye, glm::vec3 &center, glm::vec3 &up);

        glm::mat4x4 &getViewMatrix();

        void tick() override;


    };
}
