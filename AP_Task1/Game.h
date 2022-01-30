#pragma once
#include <iostream>
#include "GameComponent.h"
#include "DrawableGameComponent.h"

using namespace std;

class Game
{
public:
	void Add(GameComponent* gameComponent);
	Game(int maxComponents);
	void Run();
	typedef void FP(); //typedef representing a type of function that returns void and has no parameters
	void SetInitialise(FP* init);
	void SetTerminate(FP* term);
private:
	int componentCount = 0;
	GameComponent** components;
	FP* initialise;
	FP* terminate;
	const int TICKS_1000MS = 1000;
};

