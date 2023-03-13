#pragma once

#include "ZString.h"
#include "TArray.h"

struct SGlobalResourceIndexItem
{
	ZString m_sName;
	TArray<unsigned int> m_aResourceIndices;
};

struct SGlobalResourceIndex
{
	TArray<SGlobalResourceIndexItem> m_aItems;
};
