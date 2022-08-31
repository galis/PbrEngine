//
// Created by galismac on 24/8/2022.
//

#include "BlingPhonePass.h"
#include "../../../platform/platform.h"


static const std::string VS = R"(#version 330 core
layout(location = 0) in vec3 aVertCoord;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTextureCoord;
layout(location = 3) in vec3 aTangent;
out vec3 vNormal;
out vec2 vTextureCoord;
out vec3 vWorldCoord;
out vec3 vTangent;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
void main(){
    vTextureCoord = aTextureCoord;
    vNormal = vec3(modelMatrix*vec4(aNormal,1.0));
    vWorldCoord = vec3(modelMatrix*vec4(aVertCoord,1.0));
    vTangent = vec3(modelMatrix*vec4(aTangent,1.0));
    gl_Position = projMatrix*viewMatrix*modelMatrix* vec4(aVertCoord,1.0);
}
)";

static const std::string FS = R"(#version 330 core
precision mediump float;
in vec3 vNormal;
in vec2 vTextureCoord;
in vec3 vWorldCoord;
in vec3 vTangent;
out vec4 vFragColor;
uniform vec3 light;
uniform vec3 eye;
uniform sampler2D diffTexture;
uniform sampler2D specTexture;
uniform sampler2D normTexture;

void main(){
    vec3 diffColor = texture(diffTexture,vTextureCoord).rgb;
    vec3 specColor = texture(specTexture,vTextureCoord).rgb;
    vec3 N = normalize(vNormal);
    vec3 T = normalize(vTangent);
    vec3 B = normalize(cross(N,T));
    mat3 tbn = mat3(T,B,N);
    vec3 normal= normalize(tbn*(texture(normTexture,vTextureCoord).xyz*2.0-1.0));
    vec3 ambient = vec3(0.2);
    vec3 diff = vec3(0.5)* max(0.0,dot(normalize(light-vWorldCoord),normal));
    vec3 reflectLight = normalize(reflect(normalize(vWorldCoord-light),normal));
    vec3 viewDir = normalize(eye-vWorldCoord);
    vec3 spec = vec3(0.3)*max(0.0,dot(viewDir,reflectLight));
    vFragColor = vec4((ambient+diff+spec)*diffColor,1.0);
}
)";


pbreditor::BlingPhonePass::BlingPhonePass() : m_vao(-1), m_ebo(-1), m_vbo(-1), m_program(-1), m_fbo(-1) {

}

pbreditor::BlingPhonePass::~BlingPhonePass() {

}

int pbreditor::BlingPhonePass::render(const WindowInfo *winInfo, World *world) {
    process(world);
    glUseProgram(m_program);
    glViewport(0, 0, winInfo->width, winInfo->height);
    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDrawElements(GL_TRIANGLES, m_draw_index_num, GL_UNSIGNED_INT, 0);
    glDisable(GL_DEPTH_TEST);
    return RESULT_OK;
}

int pbreditor::BlingPhonePass::process(pbreditor::World *world) {
    if (world->getModels().empty()) return RESULT_OK;
    auto &model = world->getModels().at(0);
    model.loadModel();
    auto &mesh = world->getModels().at(0).getMeshs().at(0);
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh.m_verts.size() * sizeof(Vertex), mesh.m_verts.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.m_indexs.size() * sizeof(int), mesh.m_indexs.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid *) offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, false, sizeof(Vertex), (GLvoid *) offsetof(Vertex, coord));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid *) offsetof(Vertex, tangent));
    m_draw_index_num = mesh.m_indexs.size();

    glm::mat4x4 &modelMatrix = model.getMatrix();
    glm::mat4x4 &viewMatrix = world->getCamera()->getViewMatrix();
    glm::mat4x4 &projMatrix = world->getProjMatrix();
    glUniformMatrix4fv(glGetUniformLocation(m_program, "modelMatrix"), 1, GL_FALSE, &modelMatrix[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(m_program, "viewMatrix"), 1, GL_FALSE, &viewMatrix[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(m_program, "projMatrix"), 1, GL_FALSE, &projMatrix[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh.m_textures[0].getId());
    GLUtil::useTexParameter();
    glUniform1i(glGetUniformLocation(m_program, "diffTexture"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, mesh.m_textures[1].getId());
    GLUtil::useTexParameter();
    glUniform1i(glGetUniformLocation(m_program, "specTexture"), 1);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, mesh.m_textures[2].getId());
    GLUtil::useTexParameter();
    glUniform1i(glGetUniformLocation(m_program, "normTexture"), 2);

    glUniform3fv(glGetUniformLocation(m_program, "light"), 1, &world->getLights()[0].getPosition()[0]);
    glUniform3fv(glGetUniformLocation(m_program, "eye"), 1, &world->getCamera()->getPosition()[0]);
    return RESULT_OK;
}

int pbreditor::BlingPhonePass::init() {
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

int pbreditor::BlingPhonePass::destroy() {
    if (m_vao != -1) {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
        glDeleteFramebuffers(1, &m_fbo);
        glDeleteProgram(m_program);
        m_program = -1;
        m_vao = -1;
        m_vbo = -1;
        m_ebo = -1;
        m_fbo = -1;
    }
    return RenderPass::destroy();
}
