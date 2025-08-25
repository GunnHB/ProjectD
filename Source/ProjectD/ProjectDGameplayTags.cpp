
#include "ProjectDGameplayTags.h"

namespace ProjectDGameplayTags
{
	/* Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack, "InputTag.LightAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack, "InputTag.HeavyAttack");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light, "Player.Ability.Attack.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy, "Player.Ability.Attack.Heavy");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Combat, "Shared.Status.Combat");
	
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_EnterCombat, "Shared.Event.EnterCombat");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_LeaveCombat, "Shared.Event.LeaveCombat");
}
