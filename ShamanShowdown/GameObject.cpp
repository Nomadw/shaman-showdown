#include "GameObject.h"
#include "Controls.h"
#include "GameState.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::attachComponent(GameComponent* gameComponent)
{
	gameComponents.push_back(gameComponent);
}


void GameObject::update(GameState * state, float deltaTime, Controls* controls)
{
	for (int i = 0; i < gameComponents.size(); i++)
	{
		gameComponents[i]->update(state, deltaTime, controls, this);
	}
}