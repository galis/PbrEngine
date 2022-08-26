//
// Created by galismac on 25/8/2022.
//

#ifndef PBREDITOR_UIPASS_H
#define PBREDITOR_UIPASS_H

#include "../RenderPass.h"
#include <vector>

namespace pbreditor {

    class UiPass : public RenderPass {
    private:
        GObject *m_current_gobject;
        std::vector<GObject *> m_objects;
    public:
        UiPass();

        ~UiPass();

        int render(const WindowInfo *winInfo, World *world) override;

    };

}

#endif //PBREDITOR_UIPASS_H
