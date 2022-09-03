//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_FORWARDRENDERPIPE_H
#define PBREDITOR_FORWARDRENDERPIPE_H


#include "RenderPipe.h"
#include "pass/MainCameraPass.h"

namespace pbreditor {
    class ForwardRenderPipe : public RenderPipe {
    private:
        MainCameraPass mainCameraPass;
    public:
        ForwardRenderPipe();

        ~ForwardRenderPipe() override;

        int init() override;

        int destroy() override;

        int render(const WindowInfo *winInfo, World *world) override;
    };
}
#endif //PBREDITOR_FORWARDRENDERPIPE_H
