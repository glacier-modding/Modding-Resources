#pragma once

#include "TArray.h"
#include "ZString.h"
#include "TPair.h"

struct SEntityTemplateReference
{
	unsigned long long entityID;
	int externalSceneIndex;
	int entityIndex;
	ZString exposedEntity;
};

struct SEntityTemplatePropertyAlias
{
	ZString sAliasName;
	int entityID;
	ZString sPropertyName;
};

struct SEntityTemplateEntitySubset
{
	TArray<int> entities;
};

struct STemplateSubEntityBlueprint
{
	SEntityTemplateReference logicalParent;
	int entityTypeResourceIndex;
	unsigned long long entityId;
	ZString entityName;
	TArray<SEntityTemplatePropertyAlias> propertyAliases;
	TArray<TPair<ZString, SEntityTemplateReference>> exposedEntities;
	TArray<TPair<ZString, int>> exposedInterfaces;
	TArray<TPair<ZString, SEntityTemplateEntitySubset>> entitySubsets;
};

struct SEntityTemplatePinConnection
{
	int fromID;
	int toID;
	ZString fromPinName;
	ZString toPinName;
};

struct STemplateEntityBlueprint
{
	int subType;
	int rootEntityIndex;
	TArray<STemplateSubEntityBlueprint> entityTemplates;
	TArray<int> externalSceneTypeIndicesInResourceHeader;
	TArray<SEntityTemplatePinConnection> pinConnections;
	TArray<SEntityTemplatePinConnection> inputPinForwardings;
	TArray<SEntityTemplatePinConnection> outputPinForwardings;
	TArray<SEntityTemplateReference> overrideDeletes;
};
