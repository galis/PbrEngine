//
// Created by galismac on 25/8/2022.
//

#ifndef PBREDITOR_GLUTIL_H
#define PBREDITOR_GLUTIL_H

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif
#include <string>

namespace pbreditor {

    class GLUtil {
    public:
        static void printGLString(const char *name, GLenum s);

        static void checkGlError(const char *op);

        static GLuint loadShader(const std::string &strSource, GLuint shader_type);

        static GLuint loadProgram(const std::string &strVSource, const std::string &strFSource);

        static void useTexParameter();
    };

}

#endif //PBREDITOR_GLUTIL_H
