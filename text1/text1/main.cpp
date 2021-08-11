#include "DxLib.h"

const char TITLE[] = "TestProgram";

//ウィンドウサイズ
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

int str[50];
// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	/*ウィンドウサイズを手動では変更せず、
	ウィンドウサイズに併せて拡大できないようにする*/
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//タイトルを変更
	SetMainWindowText(TITLE);

	//画面サイズの最大サイズ,カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	//画像サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	//画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0xAF);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//(ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像などのリソースデータの変数宣言と読み込み
	int title = LoadGraph("title.png");
	LoadDivGraph("string.png", 26, 26, 1, 16, 16, str);
	//ゲームループで使う変数の宣言

	//最新のキーボード情報用
	char keys[256] = { 0 };

	//1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	//ゲームループ
	while (1)
	{
		//最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		//最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		//画面クリア
		ClearDrawScreen();

		//更新処理


		//描画処理
		DrawGraph(0, 0, title, true);
		DrawGraph(80, 32, str[12], true);
		DrawGraph(96, 32, str[0], true);
		DrawGraph(112, 32, str[17], true);
		DrawGraph(128, 32, str[8], true);
		DrawGraph(144, 32, str[14], true);

		DrawGraph(80, 48, str[2], true);

		DrawGraph(240, 48, str[2], true);
		DrawGraph(256, 48, str[1], true);
		DrawGraph(272, 48, str[1], true);
		DrawGraph(288, 48, str[1], true);

		DrawGraph(384, 32, str[22], true);
		DrawGraph(400, 32, str[14], true);
		DrawGraph(416, 32, str[17], true);
		DrawGraph(432, 32, str[11], true);
		DrawGraph(448, 32, str[3], true);

		DrawGraph(512, 32, str[19], true);
		DrawGraph(528, 32, str[8], true);
		DrawGraph(544, 32, str[12], true);
		DrawGraph(560, 32, str[4], true);

		//(ダブルバッファ)裏面
		ScreenFlip();

		//20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		//Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		//ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}