//
// Created by galismac on 29/8/2022.
//

#ifndef PBREDITOR_SKYBOXPASS_H
#define PBREDITOR_SKYBOXPASS_H

#include "../RenderPass.h"

namespace pbreditor {

    class SkyBoxPass : public RenderPass {
    private:
        GLuint m_vao, m_vbo;
        GLuint m_program;
    public:
        SkyBoxPass();

        ~SkyBoxPass() override;

        int init() override;

        int destroy() override;

        int render(const WindowInfo *winInfo, World *world) override;
    };

}

#endif //PBREDITOR_SKYBOXPASS_H
