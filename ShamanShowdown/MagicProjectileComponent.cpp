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
	int movementSpeed = deltaTime;
	switch (direction)
	{
	case SPELL_DIRECTION_UP:

		break;
	case SPELL_DIRECTION_DOWN:

		break;
	case SPELL_DIRECTION_LEFT:

		break;
	case SPELL_DIRECTION_RIGHT:

		break;
	}
}

void MagicProjectileComponent::render(Renderer * renderer)
{

}