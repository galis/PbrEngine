//
// Created by galismac on 24/8/2022.
//

#include "GModel.h"
#include "../../platform/platform.h"

pbreditor::GModel::GModel() {

}

pbreditor::GModel::~GModel() {

}

int pbreditor::GModel::loadModel(const std::string &path) {
//    if (!Resource::CheckPath(path)) {
//        return RESULT_ERROR;
//    }
    std::string &&dir = path.substr(0, path.find_last_of('/'));
    Assimp::Importer importer;
    const AiScene *scene = importer.ReadFile(path,
                                             aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
//        Platform::Debug("加载失败!");
        return RESULT_ERROR;
    }
    processNode(scene->mRootNode, scene);
    return RESULT_OK;
}

int pbreditor::GModel::processNode(AiNode *node, const AiScene *scene) {
    for (int i = 0; i < node->mNumMeshes; i++) {
        m_meshs.push_back(processMesh(scene->mMeshes[node->mMeshes[i]], scene));
    }
    for (int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
    return 0;
}

pbreditor::Mesh pbreditor::GModel::processMesh(AiMesh *mesh, const AiScene *scene) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        glm::vec3 vector;
        //处理位置
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;
        //处理法线
        if (mesh->HasNormals()) {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.normal = vector;
        }
        //处理纹理坐标
        if (mesh->mTextureCoords[0]) {
            glm::vec2 vec;
            //假设使用纹理坐标类型0
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.coord = vec;
        }
        vertices.push_back(vertex);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }
    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];

    // 1. diffuse maps
    std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    // 2. specular maps
    std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    // 3. normal maps
    std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    // 4. height maps
    std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    return pbreditor::Mesh(vertices, indices, textures);
}

std::vector<pbreditor::Texture> pbreditor::GModel::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string &&typeName) {
    std::vector<Texture> textures;
//    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
//        aiString str;
//        mat->GetTexture(type, i, &str);
//        Texture texture(dir + "/" + str.C_Str());
//        texture.load();//马上加载...
//        textures.push_back(texture);
//    }
    return textures;
}

pbreditor::Mesh::Mesh(const std::vector<Vertex> &verts, const std::vector<IndexType> &indexs, const std::vector<Texture> &textures) : m_verts(
        verts), m_indexs(indexs), m_textures(textures) {}
