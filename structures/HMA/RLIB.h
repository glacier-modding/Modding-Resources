#pragma once

#include <vector>

struct SResourceHeaderHeader
{
	unsigned int m_type;
	unsigned int m_nReferencesChunkSize;
	unsigned int m_nStatesChunkSize;
	unsigned int m_nDataSize;
	unsigned int m_nSystemMemoryRequirement;
	unsigned int m_nVideoMemoryRequirement;
};

struct SResourceLibrary
{
	SResourceHeaderHeader resourceHeaderHeader;
	std::vector<std::vector<unsigned char>> resourcesData;
};
