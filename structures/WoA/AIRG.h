#pragma once

#include "TArray.h"
#include "float4.h"
#include "ZBitArray.h"

struct SGWaypoint
{
	unsigned short nNeighbor0;
	unsigned short nNeighbor1;
	unsigned short nNeighbor2;
	unsigned short nNeighbor3;
	unsigned short nNeighbor4;
	unsigned short nNeighbor5;
	unsigned short nNeighbor6;
	unsigned short nNeighbor7;
	float4 vPos;
	unsigned int nVisionDataOffset;
	short nLayerIndex;
};

struct SGProperties
{
	float4 vMin;
	float4 vMax;
	int nGridWidth;
	float fGridSpacing;
	int nVisibilityRange;
};

struct SReasoningGrid
{
	TArray<SGWaypoint> m_WaypointList; // 0x0
	ZBitArray m_LowVisibilityBits; // 0x18
	ZBitArray m_HighVisibilityBits; // 0x38
	SGProperties m_Properties; // 0x60
	unsigned int m_nNodeCount; // 0x90
	TArray<unsigned char> m_pVisibilityData; // 0x98
	ZBitArray m_deadEndData; // 0xB0
};
