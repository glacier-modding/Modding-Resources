#pragma once

#include "TArray.h"
#include "ZString.h"
#include "ZVariant.h"

enum class EVirtualPlatformID
{
	DEFAULT = 0,
	PC = 256,
	PC_ENHANCED = 257,
	PS4 = 512,
	PS4_PRO = 513,
	XBONE = 768,
	XBONE_X = 769,
	STADIA = 1024,
	PS5 = 1280,
	XBSCARLETT = 1536,
	XBSCARLETT_ANACONDA = 1537,
	VR = 65536,
	VR_PC = 65792,
	VR_PS4 = 66048,
	VR_PS4_PRO = 66049,
	VR_PS5 = 66816,
	__SUB = 255,
	__BASE = 65280,
	__SYSTEM = 16711680,
};

struct SEntityTemplatePropertyOverride
{
	SEntityTemplateReference propertyOwner;
	SEntityTemplateProperty propertyValue;
};

struct SEntityTemplatePlatformSpecificProperty
{
	SEntityTemplateProperty propertyValue;
	EVirtualPlatformID platform;
	bool postInit;
};

struct SEntityTemplateReference
{
	unsigned long long entityID;
	int externalSceneIndex;
	int entityIndex;
	ZString exposedEntity;
};

struct SEntityTemplateProperty
{
	unsigned int nPropertyID;
	ZVariant value;
};

struct STemplateFactorySubEntity
{
	SEntityTemplateReference logicalParent;
	int entityTypeResourceIndex;
	TArray<SEntityTemplateProperty> propertyValues;
	TArray<SEntityTemplateProperty> postInitPropertyValues;
	TArray<SEntityTemplatePlatformSpecificProperty> platformSpecificPropertyValues;
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
