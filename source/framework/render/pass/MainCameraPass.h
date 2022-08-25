//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_MAINCAMERAPASS_H
#define PBREDITOR_MAINCAMERAPASS_H

#include "../RenderPass.h"
#include "../GLUtil.h"
#include <OpenGL/gl3.h>

namespace pbreditor {
    class MainCameraPass : public RenderPass {
    private:
        GLuint m_vao, m_vbo, m_ebo;
        GLuint m_program;
        GLuint m_fbo;
        int m_draw_index_num;
    public:
        MainCameraPass();

        ~MainCameraPass() override;

        int init() override;

        int destroy() override;

        int process(World *world);

        int render(const WindowInfo *winInfo) override;
    };
}

#endif //PBREDITOR_MAINCAMERAPASS_H
