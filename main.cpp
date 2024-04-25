#include "DxLib.h"
#include "player.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 画面モードのセット
	SetGraphMode(1200, 800, 16);
	ChangeWindowMode(TRUE);
	SetUseLighting(TRUE);
	SetFontSize(45);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面の更新時間の管理用変数
	LONGLONG nowCount, prevCount;                      // マイクロ秒(100万分の1秒単位で時刻取得)
	nowCount = prevCount = GetNowHiPerformanceCount();
	float fixedDeltaTime = 1.0f / 60.0f;               // 60分の1秒 = 0.01666...秒
	float waitFrameTime = 15500;                       // 16000マイクロ秒 = 16ミリ秒 = 0.016秒

	int fps = 0;			//フレームカウント

	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);
	//(90, 50, 20)の視点から(0, 45, 40)のターゲットを見る角度にカメラを設置
	SetCameraPositionAndTarget_UpVecY(VGet(90, 50, 20), VGet(0, 45, 40));

	//////////////////////////////////////////
	/// クラス宣言
	///////////////////////////////////////////

	// プレヤー
	Player* player = new Player;

	//////////////////////////////////////
	/// 初期化処理
	/////////////////////////////////////


	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// deltaTime計測
		float deltaTime;
		nowCount = GetNowHiPerformanceCount();
		deltaTime = (nowCount - prevCount) / 1000000.0f;

		// 画面を初期化する
		ClearDrawScreen();

		// 更新処理呼び出し
		player->Updata();

		// 描画処理呼び出し
		player->Draw();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		//60FPS待ち
		while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
		{
			;
		}

		prevCount = nowCount;
		//フレームカウント増加
		fps++;
		//int型の最大値を超えないための処理
		if (fps > 2000000000)
		{
			fps = 0;
		}
	}


	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}