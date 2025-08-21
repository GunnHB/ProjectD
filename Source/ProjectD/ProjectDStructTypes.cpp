
#include "ProjectDStructTypes.h"

#include "AbilitySystem/Abilities/ProjectDHeroGameplayAbility.h"

bool FProjectDHeroAbilitySets::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
