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