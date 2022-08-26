//
// Created by galismac on 24/8/2022.
//

#pragma once

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <ostream>

namespace pbreditor {
    class Transform {
    private:
        glm::vec3 m_position;
        glm::vec3 m_scale;
        glm::quat m_rotation_qua;
        glm::vec3 m_rotation;
    public:

        Transform();

        ~Transform();

        void setPositionX(float x);

        void setPositionY(float y);

        void setPositionZ(float z);

        void setPosition(glm::vec3 &position);

        void setScaleX(float x);

        void setScaleY(float y);

        void setScaleZ(float z);

        void setScale(glm::vec3 &scale);

        void setRotationX(float x);

        void setRotationY(float y);

        void setRotationZ(float z);

        void setRotation(glm::vec3 &rotation);

        glm::vec3 &getPosition();

        glm::vec3 &getRotation();

        glm::vec3 &getScale();

        friend std::ostream &operator<<(std::ostream &os, const Transform &transform);
    };
}


