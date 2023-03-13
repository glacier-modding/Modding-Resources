#pragma once

#include <vector>

struct SColorRGBA
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct SVertexDataHeader
{
    unsigned int m_nSubMeshes;
};

struct SVertexDataSubMeshHeader
{
    unsigned int m_nID;
    unsigned int m_nVertices;
};

struct SVertexDataSubMesh
{
    SVertexDataSubMeshHeader m_sSubMeshHeader;
    std::vector<SColorRGBA> m_acolors;
};

struct SVertexData
{
    SVertexDataHeader m_sHeader;
    std::vector<SVertexDataSubMesh> m_aVertexDataSubMeshes;
};
