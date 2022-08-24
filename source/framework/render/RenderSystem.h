//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_RENDERSYSTEM_H
#define PBREDITOR_RENDERSYSTEM_H

#include "RenderPipe.h"
#include <memory>

//维护RenderPipe对Mesh进行渲染
namespace pbreditor {
    class RenderSystem {
    private:
        std::unique_ptr<RenderPipe> renderPipe;
    public:
        RenderSystem();

        ~RenderSystem();

        int init();

        int destroy();

        int tick();
    };
}

#endif //PBREDITOR_RENDERSYSTEM_H
