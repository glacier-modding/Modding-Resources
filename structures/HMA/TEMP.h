#pragma once

#include "TArray.h"
#include "ZVariant.h"

struct SEntityTemplateProperty
{
	unsigned int nPropertyID;
	ZVariant value;
};

struct STemplateSubEntity
{
	int parentIndex;
	int entityTypeResourceIndex;
	TArray<SEntityTemplateProperty> propertyValues;
	TArray<SEntityTemplateProperty> postInitPropertyValues;
};

struct STemplateEntity
{
    int blueprintIndexInResourceHeader;
    int rootEntityIndex;
    TArray<STemplateSubEntity> entityTemplates;
};
