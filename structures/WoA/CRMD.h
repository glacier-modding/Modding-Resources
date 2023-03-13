#pragma once

#include "TArray.h"
#include "SVector4.h"
#include "SVector3.h"
#include "TFixedArray.h"
#include "SMatrix.h"

struct SCrowdFlowChannel
{
	TArray<unsigned char> m_aFlowVectorIndex;
	TArray<unsigned short> m_aFlowCost;
};

struct SCrowdCells
{
	TFixedArray<unsigned char> m_cells;
};

class ZCrowdGridPoint
{
	short m_nHeightOffset;
	unsigned char m_nOnNavGrid;
};

struct SCrowdMapData
{
	unsigned int m_nVersion;
	SVector4 m_vCellConsts;
	unsigned int m_nGridSizeX;
	unsigned int m_nGridSizeY;
	unsigned int m_nCellSizeX;
	unsigned int m_nCellSizeY;
	TArray<ZCrowdGridPoint> m_GridMap;
	float m_fGridMapHeightOffsetsScale;
	float m_fGridMapHeightOffsetsBias;
	TArray<SCrowdCells> m_CellFlags;
	TArray<SCrowdCells> m_CellGroups;
	int m_nGroupFlowStartChannel;
	TArray<SCrowdFlowChannel> m_aFlowChannels;
	float m_nGridCellSize;
	SMatrix m_mObjectToWorld;
	SVector3 m_vGlobalSize;
	float m_nGridGeneratorOffset;
};
