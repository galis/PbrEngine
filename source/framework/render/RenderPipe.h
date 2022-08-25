//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_RENDERPIPE_H
#define PBREDITOR_RENDERPIPE_H

#include "../window/WindowSystem.h"
#include "../base/World.h"

namespace pbreditor {
    class RenderPipe {
    private:
    public:
        RenderPipe();

        virtual ~RenderPipe();

        virtual int init();

        virtual int destroy();

        virtual int render(const WindowInfo *winInfo, World *world) = 0;
    };
}
#endif //PBREDITOR_RENDERPIPE_H
