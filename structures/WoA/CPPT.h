#pragma once

#include "TArray.h"
#include "ZVariant.h"

struct SEntityTemplateProperty
{
	unsigned int nPropertyID;
	ZVariant value;
};

struct SCppEntity
{
	int blueprintIndexInResourceHeader;
	TArray<SEntityTemplateProperty> propertyValues;
};
