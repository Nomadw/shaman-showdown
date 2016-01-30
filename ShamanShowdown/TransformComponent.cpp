#include "TransformComponent.h"

TransformComponent::TransformComponent()
{

}


TransformComponent::~TransformComponent()
{

}

void TransformComponent::render(Renderer * renderer)
{

}

void TransformComponent::update(GameState * state, float deltaTime, Controls* controls, GameObject * object)
{

}

Vector3& TransformComponent::Translation()
{
	return translationVector;
}

Vector3& TransformComponent::Rotation()
{
	return rotationVector;
}

Vector3& TransformComponent::Scale()
{
	return scaleVector;
}