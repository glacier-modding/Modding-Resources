#pragma once

#include "ZString.h"
#include "TArray.h"

struct SAudioSwitchBlueprintData
{
	ZString m_sGroupName;
	TArray<ZString> m_aSwitches;
};
