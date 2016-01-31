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
	health1 = 0;
	health2 = 0;
	health3 = 0;
	health4 = 0;
	randcount = 100;
}


UserInterfaceComponent::~UserInterfaceComponent()
{
}

void UserInterfaceComponent::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (state->getTeam(0).GetShaman() != NULL)
	{
		health1 = ((HealthComponent *)state->getTeam(0).GetShaman()->getComponent<HealthComponent>())->health * 25.0f;
	}
	if (state->getTeam(0).GetWarrior() != NULL)
	{
		health2 = ((HealthComponent *)state->getTeam(0).GetWarrior()->getComponent<HealthComponent>())->health * 25.0f;
	}
	if (state->getTeam(1).GetShaman() != NULL)
	{
		health3 = ((HealthComponent *)state->getTeam(1).GetShaman()->getComponent<HealthComponent>())->health * 25.0f;
	}
	if (state->getTeam(1 ).GetWarrior() != NULL)
	{
		health4 = ((HealthComponent *)state->getTeam(1).GetWarrior()->getComponent<HealthComponent>())->health * 25.0f;
	}
}

void UserInterfaceComponent::render(Renderer * renderer)
{
	renderer->draw(21, 225 + (health1 / 2), 1075, (health1 * 2), 20); // Red shaman health
	renderer->draw(21, 225 + (health2 / 2), 1125, (health2 * 2), 20); // Red warrior health
	renderer->draw(21, 850 + (health3 / 2), 1075, (health3 * 2), 20); // Blue shaman health
	renderer->draw(21, 850 + (health4 / 2), 1125, (health4 * 2), 20); // Blue warrior health
	renderer->draw(20, 650, 1100, 1250, 100);
}
