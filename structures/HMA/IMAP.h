#pragma once

#include <vector>
#include <string>

struct SResourceHeaderHeader
{
	unsigned int m_type;
	unsigned int m_nReferencesChunkSize;
	unsigned int m_nStatesChunkSize;
	unsigned int m_nDataSize;
	unsigned int m_nSystemMemoryRequirement;
	unsigned int m_nVideoMemoryRequirement;
};

struct IDMap
{
    SResourceHeaderHeader resourceHeaderHeader;
	std::vector<std::string> entries;
};
