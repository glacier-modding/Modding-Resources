#pragma once

#include "ZString.h"
#include "TResourcePtr.h"

class ZAnimationResource;
class ZBoneMaskResource;

struct SPackedAnimSetEntry
{
	ZString m_sName;
	TResourcePtr<ZAnimationResource> m_pAnimation;
	TResourcePtr<ZBoneMaskResource> m_pBoneMask;
};
