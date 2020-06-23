#pragma once

class Input
{
private:
	Input() {}
	~Input() {}
	Input(const Input&) {}
	Input& operator=(const Input) {}

public:

	static Input& getInstance();

	int UpdateKey();

	bool GetKeyStay(int keyCode);

	bool GetKeyDown(int keyCode);

	bool GetKeyUp(int keyCode);


private:
	int _keys[256];

	int _beforeKeys[256];
};
