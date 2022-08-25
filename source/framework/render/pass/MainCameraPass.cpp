//
// Created by galismac on 24/8/2022.
//

#include "MainCameraPass.h"
#include "../../../platform/platform.h"


static const std::string VS = R"(#version 330 core
layout(location = 0) in vec3 aVertCoord;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTextureCoord;
out vec3 vNormal;
out vec2 vTextureCoord;
void main(){
    vTextureCoord = aTextureCoord;
    vNormal = aNormal;
    gl_Position = vec4(aVertCoord.xy,0.0,1.0);
}
)";

static const std::string FS = R"(#version 330 core
precision mediump float;
in vec3 vNormal;
in vec2 vTextureCoord;
out vec4 vFragColor;
uniform sampler2D diffTexture;
uniform sampler2D specTexture;
uniform sampler2D normTexture;

void main(){
//    vec4 diffColor = texture(inputImageTexture).rgb;
    vFragColor = vec4(1.0,0.0,0.0,1.0);
}
)";


pbreditor::MainCameraPass::MainCameraPass() : m_vao(-1), m_ebo(-1), m_vbo(-1), m_program(-1), m_fbo(-1) {

}

pbreditor::MainCameraPass::~MainCameraPass() {

}

int pbreditor::MainCameraPass::render(const WindowInfo *winInfo) {
    glUseProgram(m_program);
    glViewport(0, 0, winInfo->width, winInfo->height);
    glDrawElements(GL_TRIANGLES, m_draw_index_num, GL_UNSIGNED_INT, 0);
    return RESULT_OK;
}

int pbreditor::MainCameraPass::process(pbreditor::World *world) {
    if (world->getModels().empty()) return RESULT_OK;
    auto &model = world->getModels().at(0);
    model.loadModel();
    auto &mesh = world->getModels().at(0).getMeshs().at(0);
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh.m_verts.size() * sizeof(Vertex), mesh.m_verts.data(), GL_STATIC_DRAW);
    GLUtil::checkGlError("glBufferData m_verts");
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.m_indexs.size() * sizeof(int), mesh.m_indexs.data(), GL_STATIC_DRAW);
    GLUtil::checkGlError("glBufferData m_indexs");
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid *) offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid *) offsetof(Vertex, coord));
    m_draw_index_num = mesh.m_indexs.size();
    return RESULT_OK;
}

int pbreditor::MainCameraPass::init() {
    if (m_vao == -1) {
        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);
        glGenBuffers(1, &m_ebo);
        glGenFramebuffers(1, &m_fbo);
    }
    m_program = GLUtil::loadProgram(VS, FS);
    if (!m_program) {
        return RESULT_ERROR;
    }
    return RenderPass::init();
}

int pbreditor::MainCameraPass::destroy() {
    if (m_vao != -1) {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
        glDeleteFramebuffers(1, &m_fbo);
        m_vao = -1;
        m_vbo = -1;
        m_ebo = -1;
        m_fbo = -1;
    }
    return RenderPass::destroy();
}
