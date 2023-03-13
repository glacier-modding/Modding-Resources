#pragma once

#include "ZString.h"
#include "TArray.h"

struct SEnumType
{
	ZString m_sName;
	TArray<ZString> m_aItemNames;
	TArray<unsigned int> m_aItemValues;
};
