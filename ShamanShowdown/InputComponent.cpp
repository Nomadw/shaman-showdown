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

InputComponent::InputComponent(WPARAM up, WPARAM left, WPARAM down, WPARAM right, float walkSpeed)
{
	chars[KEYS_UP] = up;
	chars[KEYS_DOWN] = down;
	chars[KEYS_LEFT] = left;
	chars[KEYS_RIGHT] = right;
	speed = walkSpeed;
}


InputComponent::~InputComponent()
{
}

void InputComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{
	TransformComponent* transform = object->transform;
	RenderComponent * render = (RenderComponent *)object->getComponent<RenderComponent>();
	float moveX = 0, moveY = 0;

	bool isMovingUp = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;

	if (controls->isKeyPressed(chars[KEYS_UP]))
	{
		isMovingUp = true;
		moveY = -1;
		render->texture = 16;
		transform->Rotation().getY() = -1;
	}
	if (controls->isKeyPressed(chars[KEYS_LEFT]))
	{
		isMovingLeft = true;
		moveX = -1;
		render->texture = 18;
		transform->Rotation().getX() = -1;
	}
	if (controls->isKeyPressed(chars[KEYS_DOWN]))
	{
		moveY = 1;
		render->texture = 17;
		transform->Rotation().getY() = 1;
	}
	if (controls->isKeyPressed(chars[KEYS_RIGHT]))
	{
		isMovingRight = true;
		moveX = 1;
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
		moveX = (moveX / hypotenuse) * deltaTime * speed;
		moveY = (moveY / hypotenuse) * deltaTime * speed;

		Map* map = static_cast<Map*>(state->FindComponentInObject<Map>());
		if (map != NULL)
		{
			int i = 12;
		}

		{
			int posx = transform->Translation().getX();
			int posy = transform->Translation().getY();

			if (isMovingRight)
			{
				int tmpYT = posy - 1;

				if (abs((tmpYT * 64) - (transform->Translation().getY() * 64.0f)) > 32.0f)
				{
					posx += moveX;

					if (map->getTiles()[posx][posy].isWalkable())
					{
						transform->Translation().setX(transform->Translation().getX() + (moveX * 2));
					}
				}
				else
				{
					posx += moveX;

					if (map->getTiles()[posx][posy].isWalkable())
					{
						transform->Translation().setX(transform->Translation().getX() + (moveX * 2));
					}
				}
			}
			else
			{
				posx += moveX;

				if (map->getTiles()[posx][posy].isWalkable())
				{
					transform->Translation().setX(transform->Translation().getX() + (moveX * 2));
				}
			}
		}

		{
			int posx = transform->Translation().getX();
			int posy = transform->Translation().getY();

			if (isMovingUp)
			{
				int tileI = posy * 64;
				float tileF = (float)tileI;

				if ((transform->Translation().getY() * 64.0f) - tileF > 32.0f)
				{
					if (map->getTiles()[posx][posy].isWalkable())
					{
						transform->Translation().setY(transform->Translation().getY() + (moveY * 2));
					}
				}
				else
				{
					posy += moveY;

					if (map->getTiles()[posx][posy].isWalkable())
					{
						transform->Translation().setY(transform->Translation().getY() + (moveY * 2));
					}
				}
			}
			else
			{
				posy += moveY;

				if (map->getTiles()[posx][posy].isWalkable())
				{
					transform->Translation().setY(transform->Translation().getY() + (moveY * 2));
				}
			}

		}
	}
}

void InputComponent::render(Renderer * renderer)
{

}