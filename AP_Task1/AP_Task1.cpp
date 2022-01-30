#include <iostream>
#include "Game.h"
#include "DrawableGameComponent.h"

//standalone function to display the words "Initialising game"
void initialise() {
    cout << "Initialising game" << endl;
}

//standalone function to display the words "Terminating game"
void terminate() {
    cout << "Terminating game" << endl;
}

int main()
{
    //new game with maxComponents = 2
    Game *game = new Game(2);
    game->SetInitialise(initialise);
    game->SetTerminate(terminate);

    //add gameComponent with id of 1
    GameComponent* gameComponent = new GameComponent();
    gameComponent->id = 1;
    game->Add(gameComponent);

    //add drawableGameComponent with id of 2
    DrawableGameComponent* drawableGameComponent = new DrawableGameComponent(0,0); //x=0, y=0
    drawableGameComponent->id = 2;
    game->Add(drawableGameComponent);

    game->Run();
}
