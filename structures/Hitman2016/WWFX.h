#pragma once

#include <vector>

#include "ZString.h"

struct SWaxFXEntry
{
	unsigned int m_nHashedWavName;
	ZString m_sWavLocale;
	unsigned int m_nRuntimeAnimSetResourceIndex;
	ZString m_sAnimationName;
	unsigned int m_nTextResourceIndex;
	unsigned int m_nLineId;
};

struct SWavFXData
{
	int m_nEntryCount;
	std::vector<WaxFXEntry> m_vWavFXEntries;
};
