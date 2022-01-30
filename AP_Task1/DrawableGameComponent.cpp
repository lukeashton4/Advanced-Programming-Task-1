#include "DrawableGameComponent.h"
#include <iostream>

using namespace std;

void DrawableGameComponent::Update()
{
	//run parent Update to save duplication of code
	GameComponent::Update();
	//Increase x/y based on current direction
	switch (direction) {
		case Up: y++; break;
		case Down: y--; break;
		case Left: x--; break;
		case Right: x++; break;
	}
	Draw();
	ChangeDirection();
}

void DrawableGameComponent::ChangeDirection()
{
	Direction newDirection = direction;
	//repeat until newDirection != direction
	while (newDirection == direction) {
		//set newDirection to random enum
		srand(time(NULL));
		newDirection = static_cast<Direction>(rand() % 4);
	}
	//only set direction to newDirection once newDirection is definitely not the same as direction
	direction = newDirection;
}

void DrawableGameComponent::Draw()
{
	cout << "Direction: " << enum_str[direction] << ". X:" << x << " Y:" << y << endl;
}
