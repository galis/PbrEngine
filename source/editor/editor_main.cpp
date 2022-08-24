#include "../framework/PbrEngine.h"

using namespace pbreditor;

int main() {
    PbrEngine pbrEngine;
    pbrEngine.init();
    pbrEngine.run();
    pbrEngine.destroy();
    return 0;
}
