//
// Created by galismac on 24/8/2022.
//

#pragma once

#include <ostream>
#include "GObject.h"

namespace pbreditor {
    enum LightType {
        POINT,
        PARRALL,
    };

    class GLight : public GObject {
    private:
        glm::vec3 m_light_color;
        LightType m_light_type;
    public:
        GLight(LightType typ, glm::vec3 &&color);

        ~GLight();

        glm::vec3 &getLightColor();

        void setLightColor(const glm::vec3 &mLightColor);

        LightType getLightType();

        void setLightType(LightType mLightType);

        friend std::ostream &operator<<(std::ostream &os, const GLight &light);

    };
}

