//
// Created by galismac on 29/8/2022.
//

#include "SkyBoxPass.h"
#include "../GLUtil.h"
#include "../../../platform/platform.h"

static const std::string VS = R"(#version 330 core
layout(location = 0) in vec3 aVertCoord;
out vec3 vTextureCoord;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
void main(){
    vTextureCoord = aVertCoord;
    vec4 pos = projMatrix*viewMatrix* vec4(aVertCoord,1.0);
    gl_Position = pos.xyww;
}
)";

static const std::string FS = R"(#version 330 core
precision mediump float;
in vec3 vTextureCoord;
out vec4 vFragColor;
uniform samplerCube skyCubeTexture;

void main(){
    vFragColor = texture(skyCubeTexture,vTextureCoord).rgba;
}
)";

static std::vector<float> S_SKY_BOX_VERTS = {
        // positions
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,

        -1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,

        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,

        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f
};

pbreditor::SkyBoxPass::SkyBoxPass() : m_vao(-1), m_vbo(-1) {

}

pbreditor::SkyBoxPass::~SkyBoxPass() {

}

int pbreditor::SkyBoxPass::init() {
    if (m_vao == -1) {
        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);
    }
    m_program = GLUtil::loadProgram(VS, FS);
    if (!m_program) {
        return RESULT_ERROR;
    }
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, S_SKY_BOX_VERTS.size() * sizeof(float), &S_SKY_BOX_VERTS[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float)*3, nullptr);
    glBindVertexArray(0);
    return RenderPass::init();
}

int pbreditor::SkyBoxPass::destroy() {
    if (m_vao != -1) {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_program);
        m_program = -1;
        m_vao = -1;
        m_vbo = -1;
    }
    return RenderPass::destroy();
}

int pbreditor::SkyBoxPass::render(const WindowInfo *winInfo, World *world) {
    if (!world->getSkyBox()) {
        return RESULT_OK;
    }
    auto skyBox = world->getSkyBox().get();
    if (skyBox->load()) {
        return RESULT_ERROR;
    }
    glViewport(0,0,winInfo->width,winInfo->height);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glUseProgram(m_program);
    glBindVertexArray(m_vao);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, skyBox->getTexture().getId());
    glUniform1i(glGetUniformLocation(m_program, "skyCubeTexture"), 0);
    glUniformMatrix4fv(glGetUniformLocation(m_program, "projMatrix"), 1, GL_FALSE, &world->getProjMatrix()[0][0]);
    glm::mat4 cameraMat = glm::mat4(glm::mat3(world->getCamera()->getViewMatrix()));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "viewMatrix"), 1, GL_FALSE, &cameraMat[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS);
    glDisable(GL_DEPTH_TEST);
    return RESULT_OK;
}
