//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_BLINGPHONEPASS_H
#define PBREDITOR_BLINGPHONEPASS_H

#include "../RenderPass.h"
#include "../GLUtil.h"
#include <OpenGL/gl3.h>

namespace pbreditor {
    class BlingPhonePass : public RenderPass {
    private:
        GLuint m_vao, m_vbo, m_ebo;
        GLuint m_program;
        GLuint m_fbo;
        int m_draw_index_num;

        int process(World *world);
    public:

        BlingPhonePass();

        ~BlingPhonePass() override;

        int init() override;

        int destroy() override;

        int render(const WindowInfo *winInfo,  World *world) override;
    };
}

#endif //PBREDITOR_BLINGPHONEPASS_H
