//
// Created by galismac on 24/8/2022.
//

#pragma once

#include <string>
#include <ostream>
#include "Transform.h"

namespace pbreditor {

    typedef int GObjectId;
    static int g_id_alloc = 0;

    enum GObjectType {
        STATIC_MESH,
        LIGHT,
        CAMERA,
        SKYBOX
    };

    class GObject : public Transform {
    private:
        GObjectId m_id;
        std::string m_name;
        GObjectType m_type;
        glm::mat4x4 m_matrix;
    public:

        GObject(GObjectType type);

        virtual ~GObject();

        GObjectId getId() const;

        void setId(GObjectId id);

        const std::string &getName() const;

        void setName(const std::string &mName);

        GObjectType getType() const;

        void setType(GObjectType mType);

        virtual void tick();

        glm::mat4x4 &getMatrix();

        friend std::ostream &operator<<(std::ostream &os, const GObject &object);

    };

}
