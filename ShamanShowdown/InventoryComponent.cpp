#include "InventoryComponent.h"
#include "TeamMemberComponent.h"
#include "GameObject.h"
#include "GameState.h"
#include "Controls.h"
#include "TransformComponent.h"
#include "MagicProjectileComponent.h"
#include "EffectsComponent.h"

InventoryComponent::InventoryComponent()
{
	inventory = queue<Items>();
}


InventoryComponent::~InventoryComponent()
{
}

void InventoryComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{
	char key;
	int team = ((TeamMemberComponent *)object->getComponent<TeamMemberComponent>())->team;
	if (team == 0) {
		key = 'Q';
	}
	else {
		key = 'O';
	}
	
	if (controls->isKeyReleased(key) && (state->getTeam(1 - team).GetWarrior() != NULL || state->getTeam(1 - team).GetShaman() != NULL))
	{
		useItem(state, team, object);
	}
}

void InventoryComponent::useItem(GameState* state, int team, GameObject* object)
{
	if (inventory.size() > 0)
	{
		Items nextItem = inventory.front();


		GameObject * missleObject = new GameObject();
		EffectsComponent* myEffects = (EffectsComponent *)(object->getComponent<EffectsComponent>());
		EffectsComponent* enemyEffects = (EffectsComponent *)(state->getTeam(1 - team).GetShaman()->getComponent<EffectsComponent>());
		
		switch (nextItem)
		{
		case MISSLE:
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
			break;
		case SUPER_SPEED:
			myEffects->addEffect(EFFECTS_SUPERSPEED);
			break;
		case SLOW_DOWN:
			enemyEffects->addEffect(EFFECTS_SLOW);
			break;
		}

		inventory.pop();
	}
}

void InventoryComponent::giveItem(Items item)
{
	inventory.push(item);
}