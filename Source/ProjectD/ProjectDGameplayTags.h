
#pragma once

#include "NativeGameplayTags.h"

namespace ProjectDGameplayTags
{
	/* Input Tags */
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack);
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack);

	/* Player Tags */
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light);
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy);

	/* Shared Tags */
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Combat);
	
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_EnterCombat);
	PROJECTD_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_LeaveCombat);
}
