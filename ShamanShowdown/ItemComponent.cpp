#include "ItemComponent.h"
#include "Renderer.h"
#include "GameState.h"
#include "Controls.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "Team.h"
#include "MissileUse.h"

ItemComponent::ItemComponent(int textureID, Items in)
{
	texture = textureID;
	item = in;
}


ItemComponent::~ItemComponent()
{
}


void ItemComponent::update(GameState* state, float deltaTime, Controls* controls, GameObject* object)
{
	x = object->transform->Translation().getX();
	y = object->transform->Translation().getY();
	size = 32.0f;

	for (int i = 0; i < 2; i++) {
		Team *team = &state->getTeam(i);
		if (team->GetWarrior() != NULL)
		{
			if (object->transform->Translation().Magnitude(team->GetWarrior()->transform->Translation()) < 0.25f) {
				if (team->GetShaman() != NULL) {
					object->requestedRemoval = true;
					switch (item)
					{
					case missle:
						team->GetShaman()->attachComponent(new MissileUse());
						break;
					default:
						break;
					}
					return;
				}
				//loat drippingboycunts = 6;
			}
		}
	}
}

void ItemComponent::render(Renderer * renderer)
{
	if (renderer->currentPass == RENDER_PASS_ITEM)
	{
		renderer->draw(texture, x * 64, y * 64, size);
	}
}