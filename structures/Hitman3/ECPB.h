#pragma once

#include "ZString.h"
#include "TArray.h"

enum class EExtendedPropertyType
{
	TYPE_RESOURCEPTR = 0,
	TYPE_INT32 = 1,
	TYPE_UINT32 = 2,
	TYPE_FLOAT = 3,
	TYPE_STRING = 4,
	TYPE_BOOL = 5,
	TYPE_ENTITYREF = 6,
	TYPE_VARIANT = 7,
};

struct SExtendedCppEntityProperty
{
	ZString propertyName;
	EExtendedPropertyType propertyType;
	bool rtEditable;
	unsigned long long extraData;
};

struct SExtendedCppEntityBlueprint
{
	TArray<SExtendedCppEntityProperty> properties;
};
