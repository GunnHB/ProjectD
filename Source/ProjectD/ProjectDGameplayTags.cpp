
#include "ProjectDGameplayTags.h"

namespace ProjectDGameplayTags
{
	/* Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Attack_Light, "InputTag.Attack.Light");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light, "Player.Ability.Attack.Light");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Combat, "Shared.Status.Combat");
	
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Combat, "Shared.Event.Combat");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Combat_ActionTaken, "Shared.Event.Combat.ActionTaken");
}
