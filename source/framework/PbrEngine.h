//
// Created by galismac on 24/8/2022.
//

#pragma once


#include <memory>
#include "PbrContext.h"

namespace pbreditor {

    class PbrEngine {
    private:
        std::shared_ptr<PbrContext> m_context;
    public:
        PbrEngine();

        bool init();

        bool destroy();

        void run();

        ~PbrEngine();
    };

}

