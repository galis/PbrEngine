//
// Created by galismac on 25/8/2022.
//

#include <stb_image.h>
#include "GLUtil.h"
#include "../../platform/platform.h"

// 获取OpenGL属性的状态
void pbreditor::GLUtil::printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    ESLog("COMPLIE#GL %s = %s\n", name, v);
}

// 检测OpenGL状态是否错误
void pbreditor::GLUtil::checkGlError(const char *op) {
    for (GLint error = glGetError(); error; error = glGetError()) {
        ESLog("COMPLIE#after %s() glError (0x%x)\n", op, error);
    }
}


//加载着色器
GLuint pbreditor::GLUtil::loadShader(const std::string &strSource, GLuint shader_type) {
    GLint compiled_status = GL_FALSE;
    GLuint shader_id = glCreateShader(shader_type);
    if (!shader_id) {
        return 0;
    }
    const char *src = strSource.c_str();
    glShaderSource(shader_id, 1, &src, nullptr);
    glCompileShader(shader_id);
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled_status);
    if (!compiled_status) {
        GLint infoLogLen = 0;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &infoLogLen);
        if (infoLogLen > 0) {
            GLchar *infoLog = new GLchar[infoLogLen];
            glGetShaderInfoLog(shader_id, infoLogLen, nullptr, infoLog);
            ESLog("COMPLIE#Could not compile %s shader:\n%s\n",
                  shader_id == GL_VERTEX_SHADER ? "vertex" : "fragment",
                  infoLog);
            delete[] infoLog;
        }
        return 0;
    }
    return shader_id;
}

//链接着色器
GLuint pbreditor::GLUtil::loadProgram(const std::string &strVSource, const std::string &strFSource) {
    GLuint vertex_id;
    GLuint frag_id;
    GLuint program_id;
    GLint compiled_status = GL_FALSE;
    vertex_id = loadShader(strVSource, GL_VERTEX_SHADER);
    if (vertex_id == 0) {
        ESLog("COMPLIE#Load Program#Vertex Shader Failed");
        return 0;
    }
    frag_id = loadShader(strFSource, GL_FRAGMENT_SHADER);
    if (frag_id == 0) {
        ESLog("COMPLIE#Load Program#Fragment Shader Failed");
        return 0;
    }
    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, frag_id);
    glLinkProgram(program_id);
    glGetProgramiv(program_id, GL_LINK_STATUS, &compiled_status);
    if (!compiled_status) {
        GLint infoLogLen = 0;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &infoLogLen);
        if (infoLogLen) {
            GLchar *infoLog = new GLchar[infoLogLen];
            glGetProgramInfoLog(program_id, infoLogLen, nullptr, infoLog);
            ESLog("COMPLIE#Could not link program:\n%s\n", infoLog);
            delete[] infoLog;
        }
        glDeleteProgram(program_id);
        program_id = 0;
    }
    glDeleteShader(vertex_id);
    glDeleteShader(frag_id);
    return program_id;
}

void pbreditor::GLUtil::useTexParameter() {
    //设置缩小过滤为使用纹理中坐标最接近的一个像素的颜色作为需要绘制的像素颜色..这里改为线性
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //设置放大过滤为使用纹理中坐标最接近的若干个颜色，通过加权平均算法得到需要绘制的像素颜色
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //设置环绕方向S，截取纹理坐标到[1/2n,1-1/2n]。将导致永远不会与border融合
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //设置环绕方向T，截取纹理坐标到[1/2n,1-1/2n]。将导致永远不会与border融合
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void pbreditor::GLUtil::loadCubeMap(std::vector<std::string>& paths, pbreditor::Texture &texture) {
    if (paths.size() != 6) return;
    if (texture.getId() == 0) {
        TextureID id;
        glGenTextures(1, &id);
        texture.setId(id);
    }
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture.getId());
    int width, height, channel;
    for (int i = 0; i < 6; i++) {
        if (paths[i].empty()) return;
        unsigned char *data = stbi_load(paths[i].c_str(), &width, &height, &channel, 0);
        if (!data || width == 0 || channel != 3) goto finish;
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        finish:
        if (data) {
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

//GLuint pbreditor::GLUtil::loadTextureLuminace(void *byteBuffer, int w, int h, GLuint texId) {
//    GLuint texture;
//    if (texId == GL_EMPTY) {
//        glGenTextures(1, &texture);
//        glBindTexture(GL_TEXTURE_2D, texture);
//        useTexParameter();
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, w, h, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE,
//                     byteBuffer);
//    } else {
//        glBindTexture(GL_TEXTURE_2D, texId);
//        useTexParameter();
//        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, w, h, GL_LUMINANCE, GL_UNSIGNED_BYTE, byteBuffer);
//        texture = texId;
//    }
//    return texture;
//}
