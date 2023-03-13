#pragma once

#include "ZVariant.h"
#include "TArray.h"
#include "ZString.h"

struct SCppEntitySubsetInfo
{
	ZString name;
	unsigned int flags;
};

struct SCppEntityBlueprint
{
	STypeID* typeName;
	TArray<SCppEntitySubsetInfo> subsets;
};
