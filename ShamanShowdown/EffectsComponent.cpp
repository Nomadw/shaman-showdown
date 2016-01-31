#include "EffectsComponent.h"



EffectsComponent::EffectsComponent()
{
}


EffectsComponent::~EffectsComponent()
{
}

void EffectsComponent::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{

}

void EffectsComponent::render(Renderer * renderer)
{

}

void EffectsComponent::removeEffect(EFFECTS effect)
{
	int tmp = ~effect;

	currentEffects &= (EFFECTS)tmp;
}

void EffectsComponent::addEffect(EFFECTS effect)
{
	currentEffects |= effect;
}

bool EffectsComponent::hasEffect(EFFECTS effect)
{
	if ((currentEffects & effect) == effect)
	{
		return true;
	}

	return false;
}