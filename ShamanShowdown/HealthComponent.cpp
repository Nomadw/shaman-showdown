#include "HealthComponent.h"
#include "GameObject.h"

HealthComponent::HealthComponent(int health)
{
	maxHealth = health;
	this->health = health;
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

float HealthComponent::HealthRaw()
{
	return health;
}

float HealthComponent::Health()
{
	return 100.0f * (health / maxHealth);
}

void HealthComponent::TakeDamage(float dmgPts)
{
	health -= dmgPts;
}