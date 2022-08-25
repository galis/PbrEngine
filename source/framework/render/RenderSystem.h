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
        std::shared_ptr<WindowInfo> m_win_info;
        std::shared_ptr<World> m_world;
        std::unique_ptr<RenderPipe> m_render_pipe;
    public:
        RenderSystem();

        ~RenderSystem();

        int init(std::shared_ptr<WindowInfo> winInfo, std::shared_ptr<World> world);

        int destroy();

        int tick();
    };
}

#endif //PBREDITOR_RENDERSYSTEM_H
