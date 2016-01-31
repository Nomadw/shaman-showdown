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
		key = 'Q';
	}
	else {
		key = 'O';
	}
	if (controls->isKeyPressed(key)) 
	{
		requestRemoval = true;
		GameObject * missleObject = new GameObject();
		missleObject->transform->Translation() = object->transform->Translation();
		missleObject->attachComponent(new MagicProjectileComponent(0, 25, state->getTeam(1-team).GetWarrior()->transform, missleObject->transform, team));
		state->addGameObject(missleObject);
	}
}

void MissileUse::render(Renderer * renderer)
{
}
