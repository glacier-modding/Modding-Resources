#pragma once

#include "TArray.h"
#include "ZString.h"

struct SUIControlBlueprintPin
{
	int m_nUnk00;
	int m_nUnk01;
	ZString m_sName;
};

struct SUIControlBlueprintProperty
{
	int m_nUnk00;
	int m_nUnk01;
	ZString m_sName;
	unsigned long long m_nUnk02;
	unsigned int m_nPropertyId;
	char _pad[4];
};

struct SUIControlBlueprint
{
	TArray<SUIControlBlueprintPin> m_aPins;
	TArray<SUIControlBlueprintProperty> m_aProperties;
};
