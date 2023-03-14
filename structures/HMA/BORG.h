#pragma once

#include "SVector3.h"

struct SBoneDefinition
{
    SVector3 Center;
    unsigned int lPrevBoneNr;
    SVector3 Size;
    char Name[34];
    unsigned char nBodyPart;
};

struct SBoneConstraintsHeader
{
    unsigned int m_lNrConstraints;
};

struct SBoneConstraint
{
    unsigned char m_Type;
    unsigned char m_BoneIndex;
};

enum class EBoneConstrainType
{
    BC_LOOKAT = 1,
    BC_ROTATION = 2
};

struct SBoneConstraintLookAt : SBoneConstraint
{
    unsigned char m_lNrTargets;
    unsigned char m_lLookAtAxis;
    unsigned char m_lUpBoneAlignmentAxis;
    unsigned char m_lLookAtFlip;
    unsigned char m_lUpFlip;
    unsigned char m_UpnodeControl;
    unsigned char m_UpNodeParentIdx;
    unsigned char m_TargetParentIdx[2];
    float m_lBoneTargetsWeights[2];
    float m_TargetPos[2][3];
    float m_UpPos[3];
};

struct SBoneConstrainRotate : SBoneConstraint
{
    unsigned char m_ReferenceBoneIdx;
    float m_TwistWeight;
};

struct SPoseBoneHeader
{
    unsigned int m_nPoseBoneArrayOffset;
    unsigned int m_nPoseBoneIndeArrayOffset;
    int m_nPoseBoneCountTotal;
    unsigned int m_nPoseEntryIndexArrayOffset;
    unsigned int m_nPoseBoneCountArrayOffset;
    int m_nPoseCount;
    unsigned int m_nNamesListOffset;
    unsigned int m_nNamesEntryIndexArrayOffset;
    unsigned int m_nFaceBoneIndexArrayOffset;
    int m_nFaceBoneCount;
};

struct SPoseBone
{
    float m_quat[4];
    float m_pos[4];
};

struct SBoneRig
{
    unsigned int m_NumberOfBones;
    unsigned int m_NumberOfAnimatedBones;
    unsigned int lBoneDefinitions;
    unsigned int BindPose;
    unsigned int BindPoseInvGlobalMats;
    unsigned int lBoneConstraintsHeader;
    unsigned int lPoseBoneHeader;
    unsigned int lInvertGlobalBones;
    void* pBoneMap;
};

struct BoneRig
{
    unsigned int headerOffset;
    SBoneRig boneRig;
};
