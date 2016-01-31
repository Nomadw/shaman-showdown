#include "MagicProjectileComponent.h"
#include "GameState.h";
#include "Controls.h";
#include "GameObject.h";
#include "Renderer.h";
#include "TransformComponent.h"
#include "TeamMemberComponent.h"

MagicProjectileComponent::MagicProjectileComponent(int textureID, SPELL_DIRECTION direction, float spellSpeed, TransformComponent* transform)
{
	this->texture = textureID;
	this->direction = direction;
	this->spellSpeed = spellSpeed;
	this->transform = new TransformComponent();
	*this->transform = *transform;
	dirVec = new Vector3();
}


MagicProjectileComponent::~MagicProjectileComponent()
{
}


void MagicProjectileComponent::update(GameState* state, float deltaTime, Controls* controls, GameObject* object)
{
	float movementSpeed = deltaTime * spellSpeed * 20.0f;
	switch (direction)
	{
	case SPELL_DIRECTION_UP:
		transform->Translation().getY() -= movementSpeed;
		break;
	case SPELL_DIRECTION_DOWN:
		transform->Translation().getY() += movementSpeed;
		break;
	case SPELL_DIRECTION_LEFT:
		transform->Translation().getX() -= movementSpeed;
		break;
	case SPELL_DIRECTION_RIGHT:
		transform->Translation().getX() += movementSpeed;
		break;
	}

	if (should)
	{
		int teamID = ((TeamMemberComponent*)object->getComponent<TeamMemberComponent>())->team;

		float dist1 = object->GetDistanceTo(*state->getTeam(abs(1 - teamID)).GetShaman()->transform);
		float dist2 = object->GetDistanceTo(*state->getTeam(abs(1 - teamID)).GetWarrior()->transform);

		if (dist1 < dist2)
		{
			*dirVec = state->getTeam(abs(1 - teamID)).GetShaman()->transform->Translation() - transform->Translation();
		}
		else
		{
			*dirVec = state->getTeam(abs(1 - teamID)).GetWarrior()->transform->Translation() - transform->Translation();
			//Vector3 dirVec = state->getTeam(abs(1 - teamID)).GetWarrior()->transform->Translation() - transform->Translation;
			//dirVec /= dirVec.Magnitude(Vector3());
			//transform->Translation() += dirVec;
		}
		*dirVec /= dirVec->Magnitude(Vector3());
		should = false;
	}

	transform->Translation() += *dirVec;
}

void MagicProjectileComponent::render(Renderer * renderer)
{
	//render here
	renderer->draw(21, transform->Translation().getX() * 64.0f, transform->Translation().getY() * 64.0f, 20, 20); // Red shaman health
}