//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_RENDERPASS_H
#define PBREDITOR_RENDERPASS_H

namespace pbreditor {
    class RenderPass {
    private:
    public:
        RenderPass();

        virtual ~RenderPass();

        virtual int init();

        virtual int destroy();

        virtual void render();
    };
}

#endif //PBREDITOR_RENDERPASS_H
