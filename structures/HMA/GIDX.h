#pragma once

#include "TArray.h"
#include "ZString.h"

struct SResourceIndexFolder
{
    ZString name;
    TArray<int> resourceIndices;
};

struct SResourceIndex
{
    TArray<SResourceIndexFolder> folders;
};
