#include "Input.h"
#include <DxLib.h>

Input &Input::getInstance()
{
	static Input inputExtension;
	return inputExtension;
}

int Input::UpdateKey()
{
	for (int i = 0; i < 256; i++)
	{
		_beforeKeys[i] = _keys[i];
	}

	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			_keys[i]++;     // 加算
		}
		else {              // 押されていなければ
			_keys[i] = 0;   // 0にする
		}
	}
	return 0;
}

bool Input::GetKeyStay(int keyCode)
{
	if (_keys[keyCode] > 0)
		return true;

	return false;
}

bool Input::GetKeyDown(int keyCode)
{
	if (_keys[keyCode] == 1)
		return true;

	return false;
}

bool Input::GetKeyUp(int keyCode)
{
	if (_keys[keyCode] == 0 && _beforeKeys[keyCode] > 0)
		return true;

	return false;
}