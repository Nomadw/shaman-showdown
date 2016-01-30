#include "InputComponent.h"
#include "Controls.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "Map.h"
#include "RenderComponent.h"

#pragma region private prototypes
void rightKey(TransformComponent* transform);
void leftKey(TransformComponent* transform);
void downKey(TransformComponent* transform);
void upKey(TransformComponent* transform);
#pragma endregion

InputComponent::InputComponent(WPARAM up, WPARAM left, WPARAM down, WPARAM right)
{
	chars[KEYS_UP] = up;
	chars[KEYS_DOWN] = down;
	chars[KEYS_LEFT] = left;
	chars[KEYS_RIGHT] = right;
}


InputComponent::~InputComponent()
{
}

void InputComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{
	TransformComponent* transform = object->transform;
	RenderComponent * render = (RenderComponent *)object->getComponent<RenderComponent>();
	float moveX = 0, moveY = 0;

	if (controls->isKeyPressed(chars[KEYS_UP]))
	{
		moveY += -1;
		render->texture = 16;
		transform->Rotation().getY() = -1;
	}
	if (controls->isKeyPressed(chars[KEYS_LEFT]))
	{
		moveX += -1;
		render->texture = 18;
		transform->Rotation().getX() = -1;
	}
	if (controls->isKeyPressed(chars[KEYS_DOWN]))
	{
		moveY += 1;
		render->texture = 17;
		transform->Rotation().getY() = 1;
	}
	if (controls->isKeyPressed(chars[KEYS_RIGHT]))
	{
		moveX += 1;
		render->texture = 19;
		transform->Rotation().getX() = 1;
	}
	if (moveX == 0 && moveY != 0) 
	{
		transform->Rotation().getX() = 0;
	}
	if (moveY == 0 && moveX != 0)
	{
		transform->Rotation().getY() = 0;
	}
	float hypotenuse = sqrt(pow(moveX, 2) + pow(moveY, 2));
	if (hypotenuse > 0)
	{
		moveX = (moveX / hypotenuse) * deltaTime;
		moveY = (moveY / hypotenuse) * deltaTime;

		Map* map = static_cast<Map*>(state->FindComponentInObject<Map>());
		if (map != NULL)
		{
			int i = 12;
		}

		{
			int posx = transform->Translation().getX() + (moveX * 2);
			int posy = transform->Translation().getY() + (moveY * 2);
			if (map->getTiles()[posx][posy].isWalkable())
			{
				transform->Translation().setX(transform->Translation().getX() + (moveX * 2));
			}
		}

		{
			int posx = transform->Translation().getX();
			int posy = transform->Translation().getY() + moveY;
			if (map->getTiles()[posx][posy].isWalkable())
			{
				transform->Translation().setY(transform->Translation().getY() + (moveY * 2));
			}
		}
	}
}

void InputComponent::render(Renderer * renderer)
{

}