#include "Common.h"
#include "Unit.h"
#include "Grid.h"
#include "Player.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	// 画面をウインドウモードにする.
	ChangeWindowMode(false);

	// 画面モードのセット
	SetGraphMode(ScreenWidth, ScreenHeight, 32);

	// ＤＸライブラリ初期化
	if (DxLib_Init() == -1) return -1;

	// 描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	Game game;
	game.Initialize();

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 裏画面をクリア
		ClearDrawScreen();

		game.Update();
		game.Draw();

		 // 裏画面と表画面を入れ替え
		ScreenFlip();
	}

	// ＤＸライブラリ使用の終了
	DxLib_End();

	// ソフトの終了
	return 0;
}
