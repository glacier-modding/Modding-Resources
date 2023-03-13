#pragma once

#include "TArray.h"
#include "ZString.h"
#include "ZVariant.h"

struct SEntityTemplatePropertyOverride
{
	SEntityTemplateReference propertyOwner;
	SEntityTemplateProperty propertyValue;
};

struct SEntityTemplateProperty
{
	unsigned int nPropertyID;
	ZVariant value;
};

struct SEntityTemplateReference
{
	unsigned long long entityID;
	int externalSceneIndex;
	int entityIndex;
	ZString exposedEntity;
};

struct STemplateFactorySubEntity
{
	SEntityTemplateReference logicalParent;
	int entityTypeResourceIndex;
	TArray<SEntityTemplateProperty> propertyValues;
	TArray<SEntityTemplateProperty> postInitPropertyValues;
};

struct STemplateEntityFactory
{
	int subType;
	int blueprintIndexInResourceHeader;
	int rootEntityIndex;
	TArray<STemplateFactorySubEntity> subEntities;
	TArray<SEntityTemplatePropertyOverride> propertyOverrides;
	TArray<int> externalSceneTypeIndicesInResourceHeader;
};
