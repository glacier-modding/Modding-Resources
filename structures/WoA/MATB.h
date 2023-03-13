#pragma once

#include <vector>

#include "ZString.h"

struct SModifier
{
	unsigned char type;
	ZString name;
};

class ZRenderMaterialEntityBlueprint
{
	std::vector<SModifier*> modifiers;
};
