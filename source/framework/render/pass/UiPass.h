//
// Created by galismac on 25/8/2022.
//

#ifndef PBREDITOR_UIPASS_H
#define PBREDITOR_UIPASS_H

#include "../RenderPass.h"

namespace pbreditor {

    class UiPass : public RenderPass {
    private:
    public:
        UiPass();

        ~UiPass();

        int render(const WindowInfo *winInfo) override;
    };

}

#endif //PBREDITOR_UIPASS_H
