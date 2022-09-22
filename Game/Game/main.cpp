#include"DxLib.h"
#include"SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* sceneMg = new SceneManager();

	delete sceneMg;

	DxLib_End();

	return 0;
}