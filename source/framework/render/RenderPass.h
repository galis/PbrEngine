//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_RENDERPASS_H
#define PBREDITOR_RENDERPASS_H

#include "RenderSystem.h"

namespace pbreditor {
    class RenderPass {
    private:
    public:
        RenderPass();

        virtual ~RenderPass();

        virtual int init();

        virtual int destroy();

        virtual int render(const WindowInfo *winInfo);
    };
}

#endif //PBREDITOR_RENDERPASS_H
