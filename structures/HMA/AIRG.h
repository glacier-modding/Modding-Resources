#pragma once

#include "TArray.h"
#include "ZBitArray.h"
#include "float4.h"

struct SGWaypoint
{
	union
	{
		struct
		{
			short nNeighbor0;
			short nNeighbor1;
			short nNeighbor2;
			short nNeighbor3;
			short nNeighbor4;
			short nNeighbor5;
			short nNeighbor6;
			short nNeighbor7;
		};

		short Neighbors[8];
	};

	float4 vPos;
};

struct SGProperties
{
	float4 vMin;
	float4 vMax;
	int nGridWidth;
	float fGridSpacing;
};

struct SReasoningGrid
{
    TArray<SGWaypoint> m_WaypointList;
    ZBitArray m_LowVisibilityBits;
    ZBitArray m_HighVisibilityBits;
    TArray<TArray<unsigned short>> m_LowVisibility;
    TArray<TArray<unsigned short>> m_HighVisibility;
    SGProperties m_Properties;
    unsigned int m_BitVisibilityCount;
    unsigned int m_nNodeCount;
};
