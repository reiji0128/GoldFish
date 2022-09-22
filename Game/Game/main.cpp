#include "DxLib.h"
#include "GameManager.h"
#include "Title.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ゲームクラス定義.
	GameManager gameMane;

	bool success = gameMane.Initialize();

	gameMane.SetFirstScene(new Title());

	if (success)
	{
		gameMane.GameLoop();
	}

	gameMane.terminate();

	return 0;
}