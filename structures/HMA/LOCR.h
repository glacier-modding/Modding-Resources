#pragma once

#include <string>
#include <vector>

struct Entry
{
    std::string locale;
    int index;
};

struct LocalizationResource
{
    char localizationCategory; //0 when references are WAVB resources and 1 when references are TELI resources
    std::vector<Entry> entries;
};
