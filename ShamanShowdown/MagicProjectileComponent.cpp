#include "MagicProjectileComponent.h"
#include "GameState.h";
#include "Controls.h";
#include "GameObject.h";
#include "Renderer.h";
#include "TransformComponent.h"
#include "TeamMemberComponent.h"

MagicProjectileComponent::MagicProjectileComponent(int textureID, float spellSpeed, TransformComponent* target, TransformComponent* start)
{
	this->texture = textureID;
	this->direction = direction;
	this->spellSpeed = spellSpeed;


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
	object->transform->Translation() += *direction;
	*position = object->transform->Translation();
}

void MagicProjectileComponent::render(Renderer * renderer)
{
	renderer->draw(21, position->getX() * 64.0f, position->getY() * 64.0f, 20, 20); // Red shaman health
}