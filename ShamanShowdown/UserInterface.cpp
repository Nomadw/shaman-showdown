#include "UserInterface.h"

#include "GameObject.h"
#include "Renderer.h"
#include "Globals.h"
//#include alcohol
//#include kim

UserInterface::UserInterface()
{
	health1 = 0;
	health2 = 0;
	health3 = 0;
	health4 = 0;
	randcount = 100;
}


UserInterface::~UserInterface()
{
}

void UserInterface::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (randcount > 0)
		randcount--;
	else {
		health1 = rand() % 90 + 10;
		health2 = rand() % 90 + 10;
		health3 = rand() % 90 + 10;
		health4 = rand() % 90 + 10;
		randcount = 100;
	}
}

void UserInterface::render(Renderer * renderer)
{
	
	renderer->draw(21, 225 + (health1 / 2), 1075, (health1 * 2), 20); // Red shaman health
	renderer->draw(21, 225 + (health2 / 2), 1125, (health2 * 2), 20); // Red warrior health
	renderer->draw(21, 850 + (health3 / 2), 1075, (health3 * 2), 20); // Blue shaman health
	renderer->draw(21, 850 + (health4 / 2), 1125, (health4 * 2), 20); // Blue warrior health
	renderer->draw(20, 650, 1100, 1250, 100);
}
