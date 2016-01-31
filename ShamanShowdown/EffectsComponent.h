#pragma once
#include "GameComponent.h"

enum EFFECTS
{
	EFFECTS_INVINCIBLE = 1,
	EFFECTS_SLOW = 2,
	EFFECTS_FREEZE = 4,
	EFFECTS_SUPERSPEED = 8,
	EFFECTS_INVERT = 16
};


inline EFFECTS operator|(EFFECTS a, EFFECTS b)
{
	return static_cast<EFFECTS>(static_cast<int>(a) | static_cast<int>(b));
}

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

class EffectsComponent : GameComponent
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
};

