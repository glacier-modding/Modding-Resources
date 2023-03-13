#pragma once

#include "TArray.h"
#include "TPair.h"
#include "ZString.h"
#include "ZVariant.h"

struct SEntityTemplateReference
{
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
	STypeID* subsetType;
	TArray<int> entities;
};

struct STemplateSubEntityBlueprint
{
	int parentIndex;
	int entityTypeResourceIndex;
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
    int rootEntityIndex;
    TArray<STemplateSubEntityBlueprint> entityTemplates;
    TArray<SEntityTemplatePinConnection> pinConnections;
    TArray<SEntityTemplatePinConnection> inputPinForwardings;
    TArray<SEntityTemplatePinConnection> outputPinForwardings;
};
