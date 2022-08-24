#include <iostream>
#include "../framework/PbrEngine.h"

using namespace pbreditor;

int main() {
    std::cout << "Hello, World!" << std::endl;
    PbrEngine pbrEngine;
    pbrEngine.init();
    pbrEngine.run();
    pbrEngine.destroy();
    return 0;
}
