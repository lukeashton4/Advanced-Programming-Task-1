#pragma warning(disable : 4996)
#include "GameComponent.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

void GameComponent::Update()
{
	//get date/time now
	auto time = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(time);
	cout << "ID: " << id << ". Last Updated: " << std::ctime(&time_now);
}
