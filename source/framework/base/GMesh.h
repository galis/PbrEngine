//
// Created by galismac on 24/8/2022.
//

#pragma once

/**
 * 支持Obj3d,FBX导入
 */
#include "GObject.h"
#include <string>

namespace pbreditor {

    class GMesh : public GObject {
    public:
        GMesh();

        virtual ~GMesh();

        void loadModel(const std::string &path);
    };
}

