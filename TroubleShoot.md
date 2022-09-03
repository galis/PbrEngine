#1.ubuntu引入glad.h问题
glad glfw加入可以参考learnopengl,必须记得glad.h要放在glfw.h之前,任何加入glfw.h请添加上glad.h.如下:
```cpp
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif
```
