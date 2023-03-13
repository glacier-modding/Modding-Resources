#pragma once

#include "TArray.h"
#include "ZString.h"
#include "ZRuntimeResourceID.h"

struct SVideoDatabaseEntry
{
	ZString VideoId;
	ZRuntimeResourceID RuntimeLocalizedVideoRid;
};

struct SVideoDatabaseData
{
	TArray<SVideoDatabaseEntry> Videos;
};
