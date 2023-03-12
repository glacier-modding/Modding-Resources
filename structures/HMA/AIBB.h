#pragma once

#include "TArray.h"
#include "ZString.h"

struct SBehaviorTreeEntityReference
{
	bool m_bList;
	ZString m_sName;
};

struct SBehaviorTreeInputPinCondition
{
	ZString m_sName;
};

struct SBehaviorTreeInfo
{
	TArray<SBehaviorTreeEntityReference> m_references;
	TArray<SBehaviorTreeInputPinCondition> m_inputPinConditions;
};
