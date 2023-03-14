#pragma once

#include <vector>
#include <string>

struct SChartType
{
    unsigned int entryCount;
    std::vector<unsigned int> referenceIndices;
    std::vector<unsigned int> animationNameOffsets;
    std::vector<std::string> names;
};
