#pragma once

#include <vector>

struct ResourceInfo
{
    unsigned long long runtimeResourceId;
    unsigned long long dataOffset;
    unsigned int compressedSizeAndIsScrambledFlag;
};

struct SResourceHeaderHeader
{
    unsigned int m_type;
    unsigned int m_nReferencesChunkSize;
    unsigned int m_nStatesChunkSize;
    unsigned int m_nDataSize;
    unsigned int m_nSystemMemoryRequirement;
    unsigned int m_nVideoMemoryRequirement;
};

struct ResourceHeader
{
    SResourceHeaderHeader resourceHeader;
    unsigned int referenceCount;
    std::vector<unsigned char> flags;
    std::vector<unsigned long long> runtimeResourceIDs;
};

struct RPKG
{
    char magic[4];
    unsigned int resourceCount;
    unsigned int resourceHeadersChunkSize;
    unsigned int resourcesChunkSize;
    std::vector<ResourceInfo> resourcesInfo;
    std::vector<ResourceHeader> resourceHeaders;
    std::vector<std::vector<unsigned char>> resourcesData;
};

struct PatchRPKG
{
    char magic[4];
    unsigned int resourceCount;
    unsigned int resourceHeadersChunkSize;
    unsigned int resourcesChunkSize;
    unsigned int unneededResourceCount;
    std::vector<unsigned long long> unneededResources;
    std::vector<ResourceInfo> resourcesInfo;
    std::vector<ResourceHeader> resourceHeaders;
    std::vector<std::vector<unsigned char>> resourcesData;
};
