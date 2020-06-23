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

	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			_keys[i]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			_keys[i] = 0;   // 0�ɂ���
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