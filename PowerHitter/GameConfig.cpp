#include "GameConfig.h"
#include <DxLib.h>



GameConfig & GameConfig::getInstance()
{
	static GameConfig gameConfig;
	return gameConfig;
}

void GameConfig::ChangeWinSize()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	if(Input::getInstance().GetKeyDown(KEY_INPUT_F7))
	{
		SetWindowSizeExtendRate(sizeArray[_sizeCount]);

		_sizeCount++;

		if (_sizeCount >= sizeof(sizeArray) / sizeof(*sizeArray))
		{
			_sizeCount = 0;
		}

		_beforeKey = key;

	}
}


