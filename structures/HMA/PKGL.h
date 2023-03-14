#pragma once

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

struct SPackageListDataSection
{
	TArray<ZString> sceneResourceIDs;
	TArray<ZString> resources;
};

struct SPackageListDataFolder
{
	ZString name;
	TArray<SPackageListDataSection> sections;
};

struct SPackageListData
{
	TArray<SPackageListDataFolder> folders;
};

struct SPackageList
{
	SResourceHeaderHeader resourceHeaderHeader;
	SPackageListData packageListData;
};
