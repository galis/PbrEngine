//
// Created by galismac on 29/8/2022.
//

#ifndef PBREDITOR_MAINCAMERAPASS_H
#define PBREDITOR_MAINCAMERAPASS_H

#include "../RenderPass.h"
#include "../GLUtil.h"
#include "BlingPhonePass.h"
#include "SkyBoxPass.h"
#include "UiPass.h"

namespace pbreditor {

    class MainCameraPass : public RenderPass {
    private:
        BlingPhonePass m_bling_phone_pass;
        SkyBoxPass m_skybox_pass;
        UiPass m_ui_pass;
    public:
        MainCameraPass();

        ~MainCameraPass() override;

        int init() override;

        int destroy() override;

        int render(const WindowInfo *winInfo, World *world) override;
    };

}

#endif //PBREDITOR_MAINCAMERAPASS_H
