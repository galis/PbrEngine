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

    class GObject : public Transform {
    private:
        GObjectId m_id;
        std::string m_name;
    public:

        GObject();

        virtual ~GObject();

        GObjectId getId() const;

        void setId(GObjectId id);

        const std::string &getName() const;

        void setName(const std::string &mName);

        void tick();

        friend std::ostream &operator<<(std::ostream &os, const GObject &object);

    };

}
