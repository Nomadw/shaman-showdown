#include "Team.h"
#include "Controls.h"
#include "GameState.h"

Team::Team()
{
	characters[0] = GameObject();
	characters[1] = GameObject();
	BuildWarrior();
	BuildShaman();
}


Team::~Team()
{
}


void Team::BuildWarrior()
{

}

void Team::BuildShaman()
{

}


void Team::update(GameState * state, float deltaTime, Controls* controls)
{
	characters[0].update(state, deltaTime, controls);
	characters[1].update(state, deltaTime, controls);

}