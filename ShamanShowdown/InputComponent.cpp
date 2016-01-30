#include "InputComponent.h"
#include "Controls.h"
#include "TransformComponent.h"
#include "GameObject.h"

#pragma region private prototypes
void rightKey(TransformComponent* transform);
void leftKey(TransformComponent* transform);
void downKey(TransformComponent* transform);
void upKey(TransformComponent* transform);
#pragma endregion

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{
	TransformComponent* transform = object->transform;

	float moveX = 0, moveY = 0;

	if (controls->isKeyPressed('W'))
	{
		moveY += -1;
	}
	if (controls->isKeyPressed('A'))
	{
		moveX += -1;
	}
	if (controls->isKeyPressed('S'))
	{
		moveY += 1;
	}
	if (controls->isKeyPressed('D'))
	{
		moveX += 1;
	}

	float hypotenuse = sqrt(pow(moveX, 2) + pow(moveY, 2));
	if (hypotenuse > 0)
	{
		transform->Translation().getX() += (moveX / hypotenuse) * deltaTime;
		transform->Translation().getY() += (moveY / hypotenuse) * deltaTime;
	}
}

void InputComponent::render(Renderer * renderer)
{

}