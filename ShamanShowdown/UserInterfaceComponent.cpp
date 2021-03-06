#include "UserInterfaceComponent.h"

#include "GameObject.h"
#include "Renderer.h"
#include "Globals.h"
#include "GameState.h"
#include "Team.h"
#include "HealthComponent.h"
//#include alcohol
//#include kim

UserInterfaceComponent::UserInterfaceComponent()
{
	for (int i = 0; i < 4; i++) {
		health.push_back(0);
		tile.push_back(0);
}
}


UserInterfaceComponent::~UserInterfaceComponent()
{
}

void UserInterfaceComponent::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (state->getTeam(0).GetShaman() != NULL)
	{
		health[0] = ((HealthComponent *)state->getTeam(0).GetShaman()->getComponent<HealthComponent>())->Health();//;
		health[0] = ((HealthComponent *)state->getTeam(0).GetShaman()->getComponent<HealthComponent>())->Health();//;
	}
	if (state->getTeam(0).GetWarrior() != NULL)
	{
		health[1] = ((HealthComponent *)state->getTeam(0).GetWarrior()->getComponent<HealthComponent>())->Health();// *25.0f;
	}
	if (state->getTeam(1).GetShaman() != NULL)
	{
		health[2] = ((HealthComponent *)state->getTeam(1).GetShaman()->getComponent<HealthComponent>())->Health();// *25.0f;
	}
	if (state->getTeam(1).GetWarrior() != NULL)
	{
		health[3] = ((HealthComponent *)state->getTeam(1).GetWarrior()->getComponent<HealthComponent>())->Health();// *25.0f;
	}
}

void UserInterfaceComponent::render(Renderer * renderer)
{
	for (unsigned int i = 0; i < health.size(); i++)
	{ 
		if (health[i] < 50 && health[i] > 25) 
		{
			tile[i] = 19;
		}
		else if (health[i] < 25) 
		{
			tile[i] = 20;
		}
		else tile[i] = 17;
	}

	renderer->draw(tile[2], 350 + (health[2] / 4), 1080, (health[2] * 4), 50); // Red shaman health
	renderer->draw(tile[3], 350 + (health[3] / 4), 1125, (health[3] * 4), 50); // Red warrior health
	renderer->draw(tile[0], 975 + (health[0] / 4), 1080, (health[0] * 4), 50); // Blue shaman health
	renderer->draw(tile[1], 975 + (health[1] / 4), 1125, (health[1] * 4), 50); // Blue warrior health
	renderer->draw(18, 620, 1100, 1250, 100);
}
