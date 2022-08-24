//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_UISYSTEM_H
#define PBREDITOR_UISYSTEM_H

#include <glfw/glfw3.h>

namespace pbreditor {
    class UISystem {
    private:
        bool m_is_init;
    public:
        UISystem();

        ~UISystem();

        void tick();

        void init();

        void destroy();
    };
}
#endif //PBREDITOR_UISYSTEM_H
