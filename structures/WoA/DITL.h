#pragma once

#include <vector>

struct SDialogSoundTemplateList
{
	unsigned int soundTagCount;
	std::vector<unsigned int> soundTagHashes;
	std::vector<unsigned int> soundTagIndices;
};
