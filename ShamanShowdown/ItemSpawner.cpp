#include "ItemSpawner.h"
#include "GameObject.h"
#include "ItemSpawner.h"
#include "ItemComponent.h"
#include "GameState.h"
#include "TransformComponent.h"

ItemSpawner::ItemSpawner(float delayIn)
{
	delay = delayIn;
	timeOut = delayIn;
}

ItemSpawner::~ItemSpawner()
{
}

void ItemSpawner::render(Renderer * renderer)
{
}

void ItemSpawner::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	if (timeOut < 0) {
		timeOut = delay;
		GameObject * item = new GameObject();
		item->attachComponent(new ItemComponent(21, MISSLE));
		state->addGameObject(item);
		item->transform->Translation().setX((rand() % 27) + 2);
		item->transform->Translation().setY((rand() % 14) + 2);
	}
	timeOut -= deltaTime;
}
