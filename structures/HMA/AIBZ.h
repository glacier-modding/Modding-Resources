#pragma once

#include "ZString.h"
#include "TArrayRef.h"

enum class ECompiledBehaviorType
{
	BT_ConditionScope = 0,
	BT_Random = 1,
	BT_Match = 2,
	BT_Sequence = 3,
	BT_BEHAVIORS_BEGIN = 4,
	BT_Dummy = 4,
	BT_Dummy2 = 5,
	BT_Error = 6,
	BT_Wait = 7,
	BT_WaitForStanding = 8,
	BT_WaitBasedOnDistanceToTarget = 9,
	BT_WaitForItemHandled = 10,
	BT_AbandonOrder = 11,
	BT_CompleteOrder = 12,
	BT_PlayAct = 13,
	BT_ConfiguredAct = 14,
	BT_PlayReaction = 15,
	BT_SimpleReaction = 16,
	BT_SituationAct = 17,
	BT_SituationApproach = 18,
	BT_SituationGetHelp = 19,
	BT_SituationFace = 20,
	BT_SituationConversation = 21,
	BT_Holster = 22,
	BT_SpeakWait = 23,
	BT_SpeakWaitWithFallbackIfAlone = 24,
	BT_ConfiguredSpeak = 25,
	BT_ConditionedConfiguredSpeak = 26,
	BT_ConditionedConfiguredAct = 27,
	BT_SpeakCustomOrDefaultDistractionAckSoundDef = 28,
	BT_SpeakCustomOrDefaultDistractionInvestigationSoundDef = 29,
	BT_SpeakCustomOrDefaultDistractionStndSoundDef = 30,
	BT_Pickup = 31,
	BT_Drop = 32,
	BT_PlayConversation = 33,
	BT_PlayAnimation = 34,
	BT_MoveToLocation = 35,
	BT_MoveToTargetKnownPosition = 36,
	BT_MoveToTargetActualPosition = 37,
	BT_MoveToInteraction = 38,
	BT_MoveToNPC = 39,
	BT_FollowTargetKnownPosition = 40,
	BT_FollowTargetActualPosition = 41,
	BT_PickUpItem = 42,
	BT_GrabItem = 43,
	BT_PutDownItem = 44,
	BT_Search = 45,
	BT_LimitedSearch = 46,
	BT_MoveTo = 47,
	BT_Reposition = 48,
	BT_SituationMoveTo = 49,
	BT_FormationMove = 50,
	BT_SituationJumpTo = 51,
	BT_AmbientWalk = 52,
	BT_AmbientStand = 53,
	BT_CrowdAmbientStand = 54,
	BT_AmbientItemUse = 55,
	BT_AmbientLook = 56,
	BT_Act = 57,
	BT_Patrol = 58,
	BT_MoveToPosition = 59,
	BT_AlertedStand = 60,
	BT_AlertedDebug = 61,
	BT_AttentionToPerson = 62,
	BT_StunnedByFlashGrenade = 63,
	BT_CuriousIdle = 64,
	BT_InvestigateWeapon = 65,
	BT_DeliverWeapon = 66,
	BT_RecoverUnconscious = 67,
	BT_GetOutfit = 68,
	BT_RadioCall = 69,
	BT_EscortOut = 70,
	BT_StashItem = 71,
	BT_CautiousSearchPosition = 72,
	BT_LockdownWarning = 73,
	BT_WakeUpUnconscious = 74,
	BT_DeadBodyInvestigate = 75,
	BT_GuardDeadBody = 76,
	BT_DragDeadBody = 77,
	BT_CuriousBystander = 78,
	BT_DeadBodyBystander = 79,
	BT_StandOffArrest = 80,
	BT_StandOffReposition = 81,
	BT_StandAndAim = 82,
	BT_CloseCombat = 83,
	BT_MoveToCloseCombat = 84,
	BT_MoveAwayFromCloseCombat = 85,
	BT_CoverFightSeasonTwo = 86,
	BT_ShootFromPosition = 87,
	BT_StandAndShoot = 88,
	BT_CheckLastPosition = 89,
	BT_ProtoSearchIdle = 90,
	BT_ProtoApproachSearchArea = 91,
	BT_ProtoSearchPosition = 92,
	BT_ShootTarget = 93,
	BT_TriggerAlarm = 94,
	BT_MoveInCover = 95,
	BT_MoveToCover = 96,
	BT_HomeAttackOrigin = 97,
	BT_Shoot = 98,
	BT_Aim = 99,
	BT_MoveToRandomNeighbourNode = 100,
	BT_MoveToRandomNeighbourNodeAiming = 101,
	BT_MoveToAndPlayCombatPositionAct = 102,
	BT_MoveToAimingAndPlayCombatPositionAct = 103,
	BT_PlayJumpyReaction = 104,
	BT_JumpyInvestigation = 105,
	BT_AgitatedPatrol = 106,
	BT_AgitatedGuard = 107,
	BT_HeroEscort = 108,
	BT_Escort = 109,
	BT_ControlledFormationMove = 110,
	BT_EscortSearch = 111,
	BT_LeadEscort = 112,
	BT_LeadEscort2 = 113,
	BT_AimReaction = 114,
	BT_FollowHitman = 115,
	BT_RideTheLightning = 116,
	BT_Scared = 117,
	BT_Flee = 118,
	BT_AgitatedBystander = 119,
	BT_SentryFrisk = 120,
	BT_SentryIdle = 121,
	BT_SentryWarning = 122,
	BT_SentryCheckItem = 123,
	BT_VIPScared = 124,
	BT_VIPSafeRoomTrespasser = 125,
	BT_DefendVIP = 126,
	BT_CautiousVIP = 127,
	BT_CautiousGuardVIP = 128,
	BT_InfectedConfused = 129,
	BT_EnterInfected = 130,
	BT_CureInfected = 131,
	BT_SickActInfected = 132,
	BT_Smart = 133,
	BT_Controlled = 134,
	BT_SpeakTest = 135,
	BT_Conversation = 136,
	BT_RunToHelp = 137,
	BT_WaitForDialog = 138,
	BT_WaitForConfiguredAct = 139,
	BT_TestFlashbangGrenadeThrow = 140,
	BT_BEHAVIORS_END = 141,
	BT_COMMANDS_BEGIN = 142,
	BT_RenewEvent = 142,
	BT_ExpireEvent = 143,
	BT_ExpireEvents = 144,
	BT_SetEventHandled = 145,
	BT_RenewSharedEvent = 146,
	BT_ExpireSharedEvent = 147,
	BT_ExpireAllEvents = 148,
	BT_CreateOrJoinSituation = 149,
	BT_JoinSituation = 150,
	BT_ForceActorToJoinSituation = 151,
	BT_JoinSituationWithActor = 152,
	BT_LeaveSituation = 153,
	BT_Escalate = 154,
	BT_GotoPhase = 155,
	BT_RenewGoal = 156,
	BT_ExpireGoal = 157,
	BT_RenewGoalOf = 158,
	BT_ExpireGoalOf = 159,
	BT_SetTension = 160,
	BT_TriggerSpotted = 161,
	BT_CopyKnownLocation = 162,
	BT_UpdateKnownLocation = 163,
	BT_TransferKnownObjectPositions = 164,
	BT_WitnessAttack = 165,
	BT_Speak = 166,
	BT_StartDynamicEnforcer = 167,
	BT_StopDynamicEnforcer = 168,
	BT_StartRangeBasedDynamicEnforcer = 169,
	BT_StopRangeBasedDynamicEnforcerForLocation = 170,
	BT_StopRangeBasedDynamicEnforcer = 171,
	BT_SetDistracted = 172,
	BT_IgnoreAllDistractionsExceptTheNewest = 173,
	BT_IgnoreDistractions = 174,
	BT_PerceptibleEntityNotifyWillReact = 175,
	BT_PerceptibleEntityNotifyReacted = 176,
	BT_PerceptibleEntityNotifyInvestigating = 177,
	BT_PerceptibleEntityNotifyInvestigated = 178,
	BT_PerceptibleEntityNotifyTerminate = 179,
	BT_LeaveDistractionAssistantRole = 180,
	BT_LeaveDistractionAssitingGuardRole = 181,
	BT_RequestSuitcaseAssistanceOverRadio = 182,
	BT_RequestSuitcaseAssistanceFaceToFace = 183,
	BT_ExpireArrestReasons = 184,
	BT_SetDialogSwitch_NPCID = 185,
	BT_InfectedAssignToFollowPlayer = 186,
	BT_InfectedRemoveFromFollowPlayer = 187,
	BT_Log = 188,
	BT_COMMANDS_END = 189,
	BT_Invalid = 190,
};

enum class ECompiledConditionType
{
	CT_IsCurrent = 0,
	CT_Current = 1,
	CT_IsExpired = 2,
	CT_HasGoal = 3,
	CT_HasGoalOnTarget = 4,
	CT_HasUnhandledGoal = 5,
	CT_MaxActorsWithGoal = 6,
	CT_MinExpired = 7,
	CT_MaxExpired = 8,
	CT_MinAge = 9,
	CT_MaxAge = 10,
	CT_IsSharedOlder = 11,
	CT_HasLongTermMemory = 12,
	CT_IsSharedEventCurrent = 13,
	CT_SharedEventCurrent = 14,
	CT_IsSharedEventExpired = 15,
	CT_MinSharedEventExpired = 16,
	CT_MaxSharedEventExpired = 17,
	CT_MinSharedEventAge = 18,
	CT_MaxSharedEventAge = 19,
	CT_IsNull = 20,
	CT_IsEqual = 21,
	CT_IsOfType = 22,
	CT_IsOfActorType = 23,
	CT_IsOfActorRank = 24,
	CT_IsOfActorRole = 25,
	CT_IsActorRoleBodyguard = 26,
	CT_IsActorRoleVIP = 27,
	CT_IsActorDeafBlind = 28,
	CT_IsActorAlive = 29,
	CT_IsActorConscious = 30,
	CT_HasConfiguredAct = 31,
	CT_HasConfiguredSpeak = 32,
	CT_IsConfiguredConditionTrue = 33,
	CT_HasTension = 34,
	CT_HasTensionOrHigher = 35,
	CT_IsAIModified = 36,
	CT_HasSameOutfit = 37,
	CT_IsLegal = 38,
	CT_IsItemLegalOnHitman = 39,
	CT_IsItemIllegalOnHitman = 40,
	CT_IsItemSuspiciousOnHitman = 41,
	CT_AreVisibleItemsLegal = 42,
	CT_AreVisibleItemsIllegal = 43,
	CT_AreVisibleItemsSuspicious = 44,
	CT_AreVisibleWeaponsLegal = 45,
	CT_AreVisibleWeaponsIllegal = 46,
	CT_AreVisibleWeaponsSuspicious = 47,
	CT_OnlyLegalWeaponsDropped = 48,
	CT_IllegalWeaponDropped = 49,
	CT_SuspiciousWeaponDropped = 50,
	CT_OnlyLegalItemsDropped = 51,
	CT_IllegalItemDropped = 52,
	CT_SuspiciousItemDropped = 53,
	CT_OnlyLegalWeaponsPickedUp = 54,
	CT_IllegalWeaponPickedUp = 55,
	CT_SuspiciousWeaponPickedUp = 56,
	CT_OnlyLegalItemsPickedUp = 57,
	CT_IllegalItemPickedUp = 58,
	CT_SuspiciousItemPickedUp = 59,
	CT_ThrownBy = 60,
	CT_GetItemBeingThrownBy = 61,
	CT_Owner = 62,
	CT_PreviousOwner = 63,
	CT_IsOwner = 64,
	CT_IsPreviousOwner = 65,
	CT_GetItemDroppedBy = 66,
	CT_CausedBy = 67,
	CT_BeingPickedUpBy = 68,
	CT_IsSuitcase = 69,
	CT_IsNotSuitcase = 70,
	CT_IsVisiblyPerceptible = 71,
	CT_HasCustomInvestigationAckSoundDef = 72,
	CT_FindStashPointsForItem = 73,
	CT_MinDistance = 74,
	CT_MaxDistance = 75,
	CT_MinActualDistance = 76,
	CT_MinActualDistance2D = 77,
	CT_MaxActualDistance = 78,
	CT_MaxActualDistance2D = 79,
	CT_ActualInsideSlice = 80,
	CT_MaxDistanceToKnownPosition = 81,
	CT_IsDistanceFromKnownToActualGreaterThan = 82,
	CT_IsDistanceFromKnownToActualLessThan = 83,
	CT_InSituation = 84,
	CT_IsActorInSituation = 85,
	CT_SituationTarget = 86,
	CT_SituationHuntTarget = 87,
	CT_IsSituationTarget = 88,
	CT_SituationFromActors = 89,
	CT_ActorsNotInSituation = 90,
	CT_SituationFromTarget = 91,
	CT_TargetsNotInSituation = 92,
	CT_MaxSituationAge = 93,
	CT_MinSituationAge = 94,
	CT_InPhase = 95,
	CT_MinPhaseAge = 96,
	CT_MaxPhaseAge = 97,
	CT_IsOrderInvalid = 98,
	CT_IsSituationOlderThanSharedEvent = 99,
	CT_HasOrder = 100,
	CT_HasPendingOrder = 101,
	CT_IsCombatDisabled = 102,
	CT_CanJoinSituation = 103,
	CT_InfectedMayFollowPlayer = 104,
	CT_CanDistractionEscalateTo = 105,
	CT_CanReactToDistractionType = 106,
	CT_CanInvestigateDistraction = 107,
	CT_IsCurrentDistractionTarget = 108,
	CT_IsNotCurrentDistractionTarget = 109,
	CT_IsHighestPriorityTypeToInvestigate = 110,
	CT_IsHighestPriorityTypeToInvestigateFor = 111,
	CT_IsHighestPriorityTypeToReact = 112,
	CT_HasBystanderSomethingElseToInvestigate = 113,
	CT_IsDistractionNewerThanCurrentOne = 114,
	CT_ShouldDistractionDiscardNewOcurrences = 115,
	CT_IsDistractionInterruptableByNewOcurrences = 116,
	CT_IsSameDistractionTypeAsTheCurrentOne = 117,
	CT_IsDistracted = 118,
	CT_HasCustomDistractionAckSoundDef = 119,
	CT_HasCustomDistractionStndSoundDef = 120,
	CT_PerceptibleEntityEndAfterReact = 121,
	CT_PerceptibleEntityEndAfterMoveTo = 122,
	CT_FindSuitcaseAssitanceForCivilian = 123,
	CT_FindSuitcaseAssitanceForSentry = 124,
	CT_IsValidForSuitcaseAssistance = 125,
	CT_SuitcaseAssistanceRequesterFaceToFace = 126,
	CT_SuitcaseAssistanceRequesterRadio = 127,
	CT_IsDistractionTargetBeingHandled = 128,
	CT_CanArrestReasonEscalateTo = 129,
	CT_IsHighestSeverityReasonToArrest = 130,
	CT_Breakpoint = 131,
	CT_Cooldown = 132,
	CT_Trigger = 133,
	CT_IsInSniperIsland = 134,
	CT_SituationIsType = 135,
	CT_IntRuntimeParamEqualsTo = 136,
	CT_IsNewArrestEnabled = 137,
	CT_IsDebugBuild = 138,
	CT_GetRandomFightTarget = 139,
	CT_IsCombatPositionActReady = 140,
	CT_CurrentSetpieceVisualDistractions = 141,
	CT_CurrentSetpieceSoundDistractions = 142,
	CT_AreBehaviorsDisabled = 143,
	CT_IsDifficultyEqual = 144,
	CT_IsDifficultyGreaterOrEqual = 145,
	CT_IsDifficultyLessOrEqual = 146,
	CT_IsSeasonTwoCombatEnabled = 147,
	CT_IsRealCombatSituation = 148,
	CT_RemoveSituationsWithDesiredNumberOfCombatants = 149,
	CT_RemoveCombatSituationsStandingDown = 150,
	CT_CombatSituationsWithDesiredNumberOfCombatants = 151,
	CT_CombatSituationsThatCanDiscardCombatants = 152,
	CT_CombatSituationsStandingDown = 153,
	CT_HasCombatFightOrder = 154,
	CT_IsAccidentDeathContext = 155,
	CT_IsAccidentScaleContext = 156,
	CT_IsAccidentVictimDisposable = 157,
	CT_IsAccidentBystandingGuardSearching = 158,
};

enum class EBehaviorTreeVariableType
{
	BTVT_Invalid = -1,
	BTVT_SceneReference = 0,
	BTVT_Contextual = 1,
	BTVT_Dynamic = 2,
	BTVT_NumTypes = 3,
};

struct SBehaviorBase
{
	ECompiledBehaviorType eBehaviorType;
};

class ZBehaviorTreeVariable
{
	EBehaviorTreeVariableType m_eType;
	unsigned int m_nIndex;
};

struct SConditionBase
{
	ECompiledConditionType eConditionType;
	unsigned int nConditionModifiers;
	ZBehaviorTreeVariable assignTo;
};

struct SConditionScope : SBehaviorBase
{
	SBehaviorBase* pChild;
	SBehaviorBase* pSibling;
	TArrayRef<SConditionBase*> conditions;
};

class ZCompiledBehaviorTree
{
	SConditionScope m_root;
	SBehaviorBase* m_pEnd;
	TArrayRef<ZString> m_sceneReferenceNames;
};
