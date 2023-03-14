#pragma once

#include <vector>

#include "ZString.h"

struct STextListEntry
{
    int m_nKey; //CRC32 hash of string reference.
    int m_nLength;
    ZString m_aText;
};

struct STextList
{
    unsigned int entryCount;
    std::vector<STextListEntry> entries;
};
