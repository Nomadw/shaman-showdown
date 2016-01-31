#include "MagicProjectileComponent.h"
#include "GameState.h";
#include "Controls.h";
#include "GameObject.h";
#include "Renderer.h";
#include "TransformComponent.h"
#include "TeamMemberComponent.h"
#include "HealthComponent.h"

MagicProjectileComponent::MagicProjectileComponent(int textureID, float spellSpeed, TransformComponent* target, TransformComponent* start, int teamIn)
{
	this->texture = textureID;
	this->direction = direction;
	this->spellSpeed = spellSpeed;

	team = teamIn;

	Vector3 s = start->Translation();
	Vector3 t = target->Translation();
	Vector3 offset = t - s;
	offset /= offset.Magnitude(Vector3());
	direction = new Vector3(offset);

	position = new Vector3();
}


MagicProjectileComponent::~MagicProjectileComponent()
{
}


void MagicProjectileComponent::update(GameState* state, float deltaTime, Controls* controls, GameObject* object)
{
		object->transform->Translation() += *direction * deltaTime * spellSpeed;
		*position = object->transform->Translation();
		GameObject* collider = checkCollision(state, &object->transform->Translation());
		
		if (collider != NULL)
		{
			object->requestedRemoval = true;
			((HealthComponent*)collider->getComponent<HealthComponent>())->health -= 20;
		}
}

void MagicProjectileComponent::render(Renderer * renderer)
{
	renderer->draw(21, position->getX() * 64.0f, (position->getY()-0.25f) * 64.0f, 32, 32); // Red shaman health
}

GameObject* MagicProjectileComponent::checkCollision(GameState* state, Vector3* position)
{
	float threshold = 48.0f / 64.0f;
	Vector3 sham;
	Vector3 war;

	if (state->getTeam(1 - team).GetWarrior() != NULL)
	{
		sham = state->getTeam(1 - team).GetWarrior()->transform->Translation();

		if (position->Magnitude(sham) < threshold)
		{
			return state->getTeam(1 - team).GetWarrior();
		}
	}

	if (state->getTeam(1 - team).GetShaman() != NULL)
	{
		sham = state->getTeam(1 - team).GetShaman()->transform->Translation();

		if (position->Magnitude(sham) < threshold)
		{
			return state->getTeam(1 - team).GetShaman();
		}
	}
	return NULL;
}