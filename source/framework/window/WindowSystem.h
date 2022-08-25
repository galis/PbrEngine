//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_WINDOWSYSTEM_H
#define PBREDITOR_WINDOWSYSTEM_H

#include <GLFW/glfw3.h>
#include <memory>
#include <string>

namespace pbreditor {
    struct WindowInfo {
        GLFWwindow *window;
        std::string name;
        int width;
        int height;
    };

    class WindowSystem {
    private:
        bool m_is_init;
        std::shared_ptr<WindowInfo> m_win_info;
    public:
        WindowSystem();

        ~WindowSystem();

        void tick();

        void init();

        void destroy();

        std::shared_ptr<WindowInfo> getWindowInfo();

    };
}
#endif //PBREDITOR_WINDOWSYSTEM_H
