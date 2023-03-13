#pragma once

#include <vector>

struct SRMaterialProperties
{
	enum class MATERIAL_FLAGS
	{
		MF_REFLECTION2D = 1,
		MF_REFRACTION2D = 2,
		MF_LIGHTING = 4,
		MF_EMISSIVE = 8,
		MF_DISCARD = 16,
		MF_LM_SKIN = 32,
		MF_PRIMCLASS_STANDARD = 64,
		MF_PRIMCLASS_LINKED = 128,
		MF_PRIMCLASS_WEIGHTED = 256,
		MF_DOFOVERRIDE = 512,
		MF_USES_DEFAULT_VS = 1024,
		MF_USES_SPRITE_SA_VS = 2048,
		MF_USES_SPRITE_AO_VS = 4096,
		MF_ALPHA = 8192,
		MF_USES_SIMPLE_SHADER = 16384,
		MF_DISABLE_INSTANCING = 32768,
		MF_LM_HAIR = 65536
	};

	unsigned int lMaterialClassType;
	unsigned int lMaterialEffectIndex;
	unsigned int lMaterialClassFlags;
	unsigned int lTransparencyFlags;
	unsigned int lMaterialDescriptor;
	unsigned int lImpactMaterial;
	unsigned int lEffectResource;
};

struct SRMaterialPropertyList : SRMaterialProperties
{
	unsigned int lPropertyList;
	unsigned int lPropertyCount;
};

enum PROPERTY_TYPE
{
	PT_FLOAT = 0,
	PT_CHAR = 1,
	PT_UINT32 = 2,
	PT_LIST = 3
};

struct SPropertyInfo
{
	unsigned int lName;
	unsigned int lData;
	unsigned int lSize;
	unsigned int lType;
};

class SProperty
{
	SPropertyInfo propertyInfo;
	void* value;
	unsigned int valueSize;
	std::vector<SProperty> childProperties;
};

struct SRenderMaterialInstance
{
	unsigned int headerOffset;
	SRMaterialPropertyList materialPropertyList;
	SProperty instanceProperty;
};
