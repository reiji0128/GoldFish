#include "DxLib.h"
#include "GameManager.h"
#include "Title.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ゲームクラス定義.
	GameManager gameMane;

	// ゲーム全体の初期化の結果を返す。trueなら成功、falseなら失敗.
	bool success = gameMane.Initialize();

	// ゲーム全体の最初のシーンの設定.
	gameMane.SetFirstScene(new Title());

	// 初期化が成功していた時.
	if (success)
	{
		// ゲームループを回す.
		gameMane.GameLoop();
	}

	// ゲームが終了した処理.
	gameMane.terminate();

	// プログラム全体の終了.
	return 0;
}