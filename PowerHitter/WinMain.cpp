#include "DxLib.h"
#include "GameConfig.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{

	ChangeWindowMode(true);

	SetWindowText("PowerHitter");

	SetGraphMode(GameConfig::WindowWidth , GameConfig::WindowHeight, 16);


	if (DxLib_Init() == -1)
	{
		return-1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SetBackgroundColor(255, 255, 255);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		Input::getInstance().UpdateKey();

		GameConfig::getInstance().ChangeWinSize();

		DrawBox(0, 721-128, 64, 720-1, 255, 1);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}