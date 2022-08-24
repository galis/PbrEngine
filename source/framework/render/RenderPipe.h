//
// Created by galismac on 24/8/2022.
//

#ifndef PBREDITOR_RENDERPIPE_H
#define PBREDITOR_RENDERPIPE_H

namespace pbreditor {
    class RenderPipe {
    private:
    public:
        RenderPipe();

        virtual ~RenderPipe();

        int init();

        int destroy();

        virtual void render() = 0;
    };
}
#endif //PBREDITOR_RENDERPIPE_H
