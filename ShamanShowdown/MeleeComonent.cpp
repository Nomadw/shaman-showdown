#include "MeleeComponent.h"
#include "Renderer.h"
#include "Controls.h"
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
			renderer->draw(1, 1, 1, 100);
		}
	}
}

void MeleeComponent::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (stabTime <0 && stabDelay < 0) 
	{
		if (controls->isKeyPressed(VK_SPACE)) 
			stabDelay = 1.0		f;
		{
			stabTime = 0.25f;
		}
	}
	stabDelay -= deltaTime;
	stabTime -= deltaTime;
}

void MeleeComponent::SetStrength(int value)
{
	strength = value;
}