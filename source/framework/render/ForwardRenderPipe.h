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
        MainCameraPass m_camera_pass;
    public:
        ForwardRenderPipe();

        ~ForwardRenderPipe() override;

        void render() override;
    };
}
#endif //PBREDITOR_FORWARDRENDERPIPE_H
