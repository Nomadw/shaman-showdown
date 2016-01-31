#include "UserInterface.h"

#include "GameObject.h"
#include "Renderer.h"
#include "Globals.h"
#include "GameState.h"
#include "Team.h"
#include "HealthComponent.h"
//#include alcohol
//#include kim

UserInterface::UserInterface()
{
	for (int i = 0; i < 4; i++) {
		health.push_back(0);
		tile.push_back(0);
	}
}


UserInterface::~UserInterface()
{
}

void UserInterface::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (state->getTeam(0).GetShaman() != NULL)
	{
		health[0] = ((HealthComponent *)state->getTeam(0).GetShaman()->getComponent<HealthComponent>())->health;//;
	}
	if (state->getTeam(0).GetWarrior() != NULL)
	{
		health[1] = ((HealthComponent *)state->getTeam(0).GetWarrior()->getComponent<HealthComponent>())->health;// *25.0f;
	}
	if (state->getTeam(1).GetShaman() != NULL)
	{
		health[2] = ((HealthComponent *)state->getTeam(1).GetShaman()->getComponent<HealthComponent>())->health;// *25.0f;
	}
	if (state->getTeam(1 ).GetWarrior() != NULL)
	{
		health[3] = ((HealthComponent *)state->getTeam(1).GetWarrior()->getComponent<HealthComponent>())->health;// *25.0f;
	}
}

void UserInterface::render(Renderer * renderer)
{
	for (unsigned int i = 0; i < health.size(); i++)
	{ 
		if (health[i] < 50 && health[i] > 25) {
			tile[i] = 23;
		}
		else if (health[i] < 25) {
			tile[i] = 24;
		}
		else tile[i] = 21;
	}

	renderer->draw(tile[0], 350 + (health[0] / 4), 1080, (health[0] * 4), 50); // Red shaman health
	renderer->draw(tile[1], 350 + (health[1] / 4), 1125, (health[1] * 4), 50); // Red warrior health
	renderer->draw(tile[2], 975 + (health[2] / 4), 1080, (health[2] * 4), 50); // Blue shaman health
	renderer->draw(tile[3], 975 + (health[3] / 4), 1125, (health[3] * 4), 50); // Blue warrior health
	renderer->draw(22, 620, 1100, 1250, 100);
}
