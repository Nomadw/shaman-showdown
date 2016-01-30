#include "GameObject.h"

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

void GameObject::render(Renderer * renderer)
{
	for (int i = 0; i < gameComponents.size(); i++)
	{
		gameComponents[i]->render(renderer);
	}
}