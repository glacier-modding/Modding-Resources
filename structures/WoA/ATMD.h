#pragma once

#include "TArray.h"
#include "ZString.h"
#include "ZVariant.h"

class ZAMDEvent
{
public:
	unsigned int m_nEventID;
	float m_fStartFraction;
	float m_fDuration;
	ZVariant m_customData;
};

class ZAMDEventTrack
{
public:
	ZString m_sName;
	TArray<ZAMDEvent> m_events;
};

class ZAMDTake
{
public:
	TArray<ZAMDEventTrack> m_eventTracks;
	ZVariant m_customData;
	int m_nSyncTrackIndex;
};
