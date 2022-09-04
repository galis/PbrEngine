#include "../framework/PbrEngine.h"

using namespace pbreditor;

#include <vector>
using namespace std;

int main() {
    PbrEngine pbrEngine;
    pbrEngine.init();
    pbrEngine.run();
    pbrEngine.destroy();
    return 0;
}
