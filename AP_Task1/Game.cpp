#include "Game.h"
#include <thread>
#include "DrawableGameComponent.h"

using namespace std;

void Game::Add(GameComponent *gameComponent)
{
	//set current component to given gameComponent
	components[componentCount] = gameComponent;
	//increase component count so we don't overwrite existing component
	componentCount++;
}

Game::Game(int maxComponents)
{
	//initialise components to maximum number of components
	components = new GameComponent * [maxComponents];
}

void Game::Run()
{
	//run standalone function passed into SetInitialise
	initialise();
	//repeat 5 times
	for (int c = 0; c < 5; c++) {
		//loop through all components
		for (int n = 0; n < componentCount; n++) {
			components[n]->Update(); //run update with current time
		}
		//wait a second before running again
		std::this_thread::sleep_for(std::chrono::milliseconds(TICKS_1000MS));
	}
	//run standalone function passed into SetTerminate
	terminate();
}

void Game::SetInitialise(FP* init)
{
	//set initialise to the address of a standalone function
	initialise = init;
}

void Game::SetTerminate(FP* term)
{
	//set terminate to the address of a standalone function
	terminate = term;
}
