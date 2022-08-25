//
// Created by galismac on 24/8/2022.
//

#pragma once

/**
 * 支持Obj3d,FBX导入
 */
#include <string>
#include <glm/glm.hpp>
#include <vector>
#include "GObject.h"
#include "Texture.h"
#include "assimp_compat.h"

//物体的原始数据
namespace pbreditor {

    typedef uint32_t IndexType;

    struct Vertex {
    public:
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 coord;
    };

    struct Mesh {
        std::vector<Vertex> m_verts;
        std::vector<IndexType> m_indexs;
        std::vector<Texture> m_textures;

        Mesh(const std::vector<Vertex> &verts, const std::vector<IndexType> &indexs, const std::vector<Texture> &textures);
    };

    class GModel : public GObject {
    private:
        std::string m_path;
        std::vector<Mesh> m_meshs;
        bool m_is_load;
    public:
        GModel(std::string &&path);

        virtual ~GModel();

        int loadModel();

        int processNode(AiNode *node, const AiScene *scene);

        Mesh processMesh(AiMesh *mesh, const AiScene *scene);

        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string &&typeName);

        const std::string &getPath() const;

        const std::vector<Mesh> &getMeshs() const;
    };
}

