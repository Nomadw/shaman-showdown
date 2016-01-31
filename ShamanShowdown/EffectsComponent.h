#pragma once
#include "GameComponent.h"
#include <map>

enum EFFECTS
{
	EFFECTS_SLOW = 1,
	EFFECTS_SUPERSPEED = 2
};



inline EFFECTS operator|=(EFFECTS a, EFFECTS b)
{
	return static_cast<EFFECTS>(static_cast<int>(a) | static_cast<int>(b));
}

inline EFFECTS operator&(EFFECTS a, EFFECTS b)
{
	return static_cast<EFFECTS>(static_cast<int>(a) & static_cast<int>(b));
}

inline EFFECTS operator&=(EFFECTS a, EFFECTS b)
{
	return static_cast<EFFECTS>(static_cast<int>(a) & static_cast<int>(b));
}

class EffectsComponent : public GameComponent
{
public:
	EffectsComponent();
	~EffectsComponent();

	void update(GameState * state, float deltaTime, Controls * controls, GameObject * object);
	void render(Renderer * renderer);

	void removeEffect(EFFECTS effect);
	void addEffect(EFFECTS effect);

	bool hasEffect(EFFECTS effect);

private:
	EFFECTS currentEffects;

	std::map<EFFECTS, float> effectStartTimes;
	std::map<EFFECTS, float> effectTimeActive;

	const int EFFECT_TOTAL_COUNT = 5;
};

