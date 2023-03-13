#pragma once

#include <vector>

struct SColorRGB
{
    float r;
    float g;
    float b;
};

struct SColorRGBA
{
    float r;
    float g;
    float b;
    float a;
};

struct SVector2
{
    float x;
    float y;
};

struct SVector3
{
    float x;
    float y;
    float z;
};

struct SVector4
{
    float x;
    float y;
    float z;
    float w;
};

enum class ModifierType
{
    UInt32 = 1,
    SColorRGB,
    SColorRGBA,
    Float,
    SVector2,
    SVector3,
    SVector4
};

struct SModifier
{
	unsigned char type;
	void* value;
};

struct SRenderMaterialEntity
{
private:
	std::vector<SModifier*> modifiers;
};
