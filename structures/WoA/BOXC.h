#pragma once

#include <vector>

#include "SVector3.h"

struct Cubemap
{
	SVector3 position;
	std::vector<char> textureData;
};

struct SRenderBoxReflectionCache
{
	unsigned int cubemapCount;
	std::vector<Cubemap> cubemaps;
};
