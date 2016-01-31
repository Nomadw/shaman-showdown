#include "GameObject.h"
#include "TransformComponent.h"

GameObject::GameObject()
{
	transform = new TransformComponent();
	attachComponent(transform);
	requestedRemoval = false;
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
	for (int i = 0; i < gameComponents.size(); i++)
	{
		if (gameComponents[i]->requestRemoval) 
		{
			gameComponents.erase(gameComponents.begin() + i);
			i--;
		}
	}
}

void GameObject::render(Renderer * renderer)
{
	for (int i = 0; i < gameComponents.size(); i++)
	{
		gameComponents[i]->render(renderer);
	}
}

float GameObject::GetDistanceTo(TransformComponent transform)
{
	//return this->transform->
	return NULL;
}