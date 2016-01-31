#include "HealthComponent.h"
#include "GameObject.h"

HealthComponent::HealthComponent()
{
	health = 5;
}


HealthComponent::~HealthComponent()
{
}


void HealthComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{
	if (health <= 0)
	{
		object->requestedRemoval = true;
	}
}