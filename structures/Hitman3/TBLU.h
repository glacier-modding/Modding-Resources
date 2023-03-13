#pragma once

#pragma once

#include "TArray.h"
#include "TPair.h"
#include "ZString.h"
#include "ZVariant.h"

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

struct SEntityTemplateExposedEntity
{
	ZString sName;
	bool bIsArray;
	TArray<SEntityTemplateReference> aTargets;
};

struct SEntityTemplateEntitySubset
{
	TArray<int> entities;
};

struct STemplateBlueprintSubEntity
{
	SEntityTemplateReference logicalParent;
	int entityTypeResourceIndex;
	unsigned long long entityId;
	bool editorOnly;
	ZString entityName;
	TArray<SEntityTemplatePropertyAlias> propertyAliases;
	TArray<SEntityTemplateExposedEntity> exposedEntities;
	TArray<TPair<ZString, int>> exposedInterfaces;
	TArray<TPair<ZString, SEntityTemplateEntitySubset>> entitySubsets;
};

struct SEntityTemplatePinConnection
{
	int fromID;
	int toID;
	ZString fromPinName;
	ZString toPinName;
	ZVariant constantPinValue;
};

struct SExternalEntityTemplatePinConnection
{
	SEntityTemplateReference fromEntity;
	SEntityTemplateReference toEntity;
	ZString fromPinName;
	ZString toPinName;
	ZVariant constantPinValue;
};

struct STemplateEntityBlueprint
{
	int subType;
	int rootEntityIndex;
	TArray<STemplateBlueprintSubEntity> subEntities;
	TArray<int> externalSceneTypeIndicesInResourceHeader;
	TArray<SEntityTemplatePinConnection> pinConnections;
	TArray<SEntityTemplatePinConnection> inputPinForwardings;
	TArray<SEntityTemplatePinConnection> outputPinForwardings;
	TArray<SEntityTemplateReference> overrideDeletes;
	TArray<SExternalEntityTemplatePinConnection> pinConnectionOverrides;
	TArray<SExternalEntityTemplatePinConnection> pinConnectionOverrideDeletes;
};
