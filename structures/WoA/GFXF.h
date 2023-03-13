#pragma once

#include "ZString.h"
#include "TArray.h"

struct SScaleformGFxResource
{
	unsigned char* m_pSwfData;
	size_t m_nSwfDataSize;
	TArray<ZString> m_pAdditionalFileNames;
	TArray<TArray<unsigned char>> m_pAdditionalFileData;
};
