#pragma once
#include "Input.h"

class GameConfig
{
private:

	GameConfig() {}
	~GameConfig() {}
	GameConfig(const GameConfig&) {}
	GameConfig& operator=(const GameConfig) {}

public:

	static GameConfig& getInstance();

	static const int WindowWidth = 1280;
	static const int WindowHeight = 720;

	

	void ChangeWinSize();


private:
	double sizeArray[4] = { 1.5,0.5,0.75,1.0 };

	int _sizeCount = 0;

	int _beforeKey;
};
