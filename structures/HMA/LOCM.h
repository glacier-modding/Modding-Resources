#pragma once

#include <string>
#include <vector>

struct Entry
{
    std::string locale;
    int index;
};

struct MultiLanguageResource
{
    char localizationCategory; //Always 1 because LOCM is referencing only TELI resources
    std::vector<Entry> entries;
};
