#include "EffectsComponent.h"
#include <time.h>
#include <Windows.h>

EffectsComponent::EffectsComponent()
{
	effectTimeActive[EFFECTS_SUPERSPEED] = 5;
	effectTimeActive[EFFECTS_SLOW] = 5;
}


EffectsComponent::~EffectsComponent()
{
}

void EffectsComponent::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	for (int i = 0; i < EFFECT_TOTAL_COUNT; i++)
	{
		if (hasEffect((EFFECTS)(1 << i)))
		{
			effectStartTimes[(EFFECTS)(1 << i)] -= deltaTime;

			if (effectStartTimes[((EFFECTS)(1 << i))] < 0)
			{
				effectStartTimes[(EFFECTS)(1 << i)] = 0;
				removeEffect((EFFECTS)(1 << i));
			}
		}
	}
}

void EffectsComponent::render(Renderer * renderer)
{

}

void EffectsComponent::removeEffect(EFFECTS effect)
{
	int tmp = ~effect;

	currentEffects = (EFFECTS)((int)currentEffects & tmp);
}

void EffectsComponent::addEffect(EFFECTS effect)
{
	currentEffects = (EFFECTS)((int)currentEffects | (int)effect);

	effectStartTimes[effect] = effectTimeActive[effect];
}

bool EffectsComponent::hasEffect(EFFECTS effect)
{
	if ((currentEffects & effect) == effect)
	{
		return true;
	}

	return false;
}