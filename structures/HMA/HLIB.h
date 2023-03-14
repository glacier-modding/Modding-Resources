#pragma once

#include <vector>
#include <string>

#include "TArray.h"
#include "ZString.h"

struct SResourceHeaderHeader
{
	unsigned int m_type;
	unsigned int m_nReferencesChunkSize;
	unsigned int m_nStatesChunkSize;
	unsigned int m_nDataSize;
	unsigned int m_nSystemMemoryRequirement;
	unsigned int m_nVideoMemoryRequirement;
};

struct SHeaderLibraryChunk
{
	ZString sLibraryID;
	unsigned int nOffset;
	char nFlags;
	unsigned int localizationCategory;
	TArray<ZString> sLanguages;
	TArray<int> states;
	TArray<TArray<unsigned char>> resourceHeaders;
	TArray<unsigned int> ridMappingIndices;
	TArray<unsigned long long> ridMappingIDs;
};

struct SHeaderLibrary
{
	TArray<SHeaderLibraryChunk> chunks;
	TArray<ZString> externalResourceIds;
	long long ridSource;
};

struct HeaderLibrary
{
	SResourceHeaderHeader resourceHeaderHeader;
	unsigned int referenceCount;
	unsigned int firstFlagOffset;
	unsigned int firstResourceIDOffset;
	unsigned int firstReferenceFlag;
	std::vector<unsigned int> resourceIDOffsets;
	std::vector<std::string> resourceIDs;
	SHeaderLibrary headerLibrary;
};
