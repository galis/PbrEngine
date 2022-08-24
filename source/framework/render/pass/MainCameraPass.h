//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_MAINCAMERAPASS_H
#define PBREDITOR_MAINCAMERAPASS_H

#include "../RenderPass.h"

namespace pbreditor {
    class MainCameraPass : public RenderPass {
    public:
        MainCameraPass();

        ~MainCameraPass() override;

        void render() override;
    };
}

#endif //PBREDITOR_MAINCAMERAPASS_H
