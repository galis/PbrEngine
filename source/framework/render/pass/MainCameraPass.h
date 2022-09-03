//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_MAINCAMERAPASS_H
#define PBREDITOR_MAINCAMERAPASS_H

#include "../RenderPass.h"
#include "../GLUtil.h"

namespace pbreditor {
    class MainCameraPass : public RenderPass {
    private:
        GLuint m_vao, m_vbo, m_ebo;
        GLuint m_program;
        GLuint m_fbo;
        int m_draw_index_num;

        int process(World *world);
    public:

        MainCameraPass();

        ~MainCameraPass() override;

        int init() override;

        int destroy() override;

        int render(const WindowInfo *winInfo,  World *world) override;
    };
}

#endif //PBREDITOR_MAINCAMERAPASS_H
