#pragma once
//STL Includes

//Custom Includes
#include "GameComponent.h"
#include "Vector3.h"

using namespace std;
class TransformComponent : public GameComponent
{
#pragma region Variables
public:
private:
	Vector3 translationVector;
	Vector3 rotationVector;
	Vector3 scaleVector;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	TransformComponent();
	~TransformComponent();
#pragma endregion

#pragma region Mutators
public:
	Vector3& Translation();
	Vector3& Rotation();
	Vector3& Scale();
private:
#pragma endregion

#pragma region Functions
public:
	//Overriders for the abstract base GameComponent
	void update();
	void render();

private:
#pragma endregion

private:
};
