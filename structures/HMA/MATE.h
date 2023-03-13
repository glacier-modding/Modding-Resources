#pragma once

#include <vector>

struct SRenderMaterialEffect
{
    unsigned int effectDataOffset;
    unsigned int effectDataSize;
    unsigned long long unknown; //Seems that it's always 0
    std::vector<unsigned char> effectData;
};
