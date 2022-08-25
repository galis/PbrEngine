//
// Created by galismac on 24/8/2022.
//

#pragma once

#include "glm/glm.hpp"
#include "window/WindowSystem.h"
#include "input/InputSystem.h"
#include "render/RenderSystem.h"
#include "../framework/base/World.h"

namespace pbreditor {
    class PbrContext {
    private:
        bool m_is_ortho;//是否正交投影
        bool m_is_forward;//是否前向渲染
        bool m_is_fxaa;//是否fxaa处理
        glm::vec2 m_screen_size;//屏幕大小

        WindowSystem m_window_system;
        InputSystem m_input_system;
        RenderSystem m_render_system;

        std::shared_ptr<World> m_world;
    public:

        PbrContext();

        ~PbrContext();

        void startSystems();

        void tick();

        void closeSystems();

    };
}
