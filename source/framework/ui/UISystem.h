//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_UISYSTEM_H
#define PBREDITOR_UISYSTEM_H

#include <GLFW/glfw3.h>

namespace pbreditor {
    class UISystem {
    private:
        bool m_is_init;
        GLFWwindow *m_window;
    public:
        UISystem();

        ~UISystem();

        void tick();

        void init();

        void destroy();
    };
}
#endif //PBREDITOR_UISYSTEM_H
