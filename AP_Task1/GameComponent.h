#pragma once

using namespace std;

class GameComponent
{
public:
	GameComponent() {};
	virtual void Update();
	int id;
private:
	int instances;
};

