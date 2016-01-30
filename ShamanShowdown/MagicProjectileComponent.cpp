#include "MagicProjectileComponent.h"
#include "GameState.h";
#include "Controls.h";
#include "GameObject.h";
#include "Renderer.h";
#include "TransformComponent.h"

MagicProjectileComponent::MagicProjectileComponent(int textureID, SPELL_DIRECTION direction, float spellSpeed)
{
	this->texture = textureID;
	this->direction = direction;
	this->spellSpeed = spellSpeed;
}


MagicProjectileComponent::~MagicProjectileComponent()
{
}

void MagicProjectileComponent::update(GameState* state, float deltaTime, Controls* controls, GameObject* object)
{
	float movementSpeed = deltaTime * spellSpeed;
	switch (direction)
	{
	case SPELL_DIRECTION_UP:
		object->transform->Translation().getY() -= movementSpeed;
		break;
	case SPELL_DIRECTION_DOWN:
		object->transform->Translation().getY() += movementSpeed;
		break;
	case SPELL_DIRECTION_LEFT:
		object->transform->Translation().getX() -= movementSpeed;
		break;
	case SPELL_DIRECTION_RIGHT:
		object->transform->Translation().getX() += movementSpeed;
		break;
	}
}

void MagicProjectileComponent::render(Renderer * renderer)
{

}