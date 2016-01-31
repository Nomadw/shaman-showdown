#include "MissileUse.h"
#include "Controls.h"
#include "TeamMemberComponent.h"
#include "GameObject.h"
#include "MagicProjectileComponent.h"
#include "Team.h"
#include "TransformComponent.h"
#include "GameState.h"

MissileUse::MissileUse()
{
}


MissileUse::~MissileUse()
{
}

void MissileUse::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	char key;
	int team = ((TeamMemberComponent *)object->getComponent<TeamMemberComponent>())->team;
	if (team == 0) {
		key = 'Y';
	}
	else {
		key = 'O';
	}
	if (controls->isKeyPressed(key) && (state->getTeam(1 - team).GetWarrior() != NULL || state->getTeam(1 - team).GetShaman() != NULL))
	{
		requestRemoval = true;
		GameObject * missleObject = new GameObject();
		missleObject->transform->Translation() = object->transform->Translation();
		if (state->getTeam(1 - team).GetWarrior() != NULL)
		{
			missleObject->attachComponent(new MagicProjectileComponent(0, 25, state->getTeam(1 - team).GetWarrior()->transform, missleObject->transform, team));
		}
		else if (state->getTeam(1 - team).GetShaman() != NULL)
		{
			missleObject->attachComponent(new MagicProjectileComponent(0, 25, state->getTeam(1 - team).GetShaman()->transform, missleObject->transform, team));
		}
		state->addGameObject(missleObject);
	}
}

void MissileUse::render(Renderer * renderer)
{
}
