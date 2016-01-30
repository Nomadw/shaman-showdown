#include "TransformComponent.h"

TransformComponent::TransformComponent()
{

}


TransformComponent::~TransformComponent()
{

}

void TransformComponent::update()
{

}

void TransformComponent::render()
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