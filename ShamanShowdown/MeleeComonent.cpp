#include "MeleeComponent.h"
#include "Renderer.h"
#include "Controls.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "TeamMemberComponent.h"
#include "Team.h"
#include "GameState.h"
#include "HealthComponent.h"

MeleeComponent::MeleeComponent()
{
	stabTime = 0;
	stabDelay = 0;
}


MeleeComponent::~MeleeComponent()
{
}

int MeleeComponent::GetStrength()
{
	return strength;
}

void MeleeComponent::render(Renderer * renderer)
{
	if (renderer->currentPass == RENDER_PASS_CHARACTER) 
	{
		if (stabTime > 0)
		{
			renderer->draw(0, stab.getX() * 64.0f, (stab.getY() - 0.5f) * 64.0f, 32.0f);
		}
	}
}

void MeleeComponent::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (stabTime <0 && stabDelay < 0) 
	{
		if (controls->isKeyPressed(VK_SPACE)) 
		{
			stabDelay = 1.0f;
			stabTime = 0.25f;
		}
	}
	if (stabTime > 0)
	{
		stab = object->transform->Translation() + (object->transform->Rotation() * 0.5f);
		int teamID = ((TeamMemberComponent*)object->getComponent<TeamMemberComponent>())->team;
		Team * team;
		if (teamID == 0)
		{
			teamID = 1;
		}
		else{
			teamID = 0;
		}
		team = &state->getTeam(teamID);
		for (int i = 0; i < 2; i++)
		{
			if (team->characters[i] != NULL)
			{
				if (stab.Magnitude(team->characters[i]->transform->Translation()) < 0.35f)
				{
					((HealthComponent*)team->characters[i]->getComponent<HealthComponent>())->health -= deltaTime * 20;
				}
			}
		}
	}
	stabDelay -= deltaTime;
	stabTime -= deltaTime;
}

void MeleeComponent::SetStrength(int value)
{
	strength = value;
}