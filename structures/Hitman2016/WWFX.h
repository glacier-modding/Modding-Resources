#pragma once

#include <vector>

#include "ZString.h"

struct WaxFXEntry
{
	unsigned int nHashedWavName;
	ZString sWavLocale;
	unsigned int nRuntimeAnimSetResourceIndex;
	ZString sAnimationName;
	unsigned int nTextResourceIndex;
	unsigned int nLineId;
};

struct SWavFXData
{
	int nEntryCount;
	std::vector<WaxFXEntry> wavFXEntries;
};
