#include "DxLib.h"
#include "FrameCounter.h"
#include "player.h"
#include "BackGroundManager.h"
#include "CameraController.h"
#include "ObstacleManager.h"
#include "Judge.h"
#include "Scene.h"
#include "UImanager.h"
#include "Score.h"
#include "EffectController.h"

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

	bool gameStartFlg = false; // ゲーム開始フラグ

	//////////////////////////////////////////
	/// クラス宣言
	///////////////////////////////////////////
	
	FrameCounter*	   frameConter		 = new FrameCounter();      // フレームカウンター
	CameraController*  camera			 = new CameraController();  // カメラ	
	Scene*             sceneController	 = new Scene();             // シーンコントロール	
	Player*            player			 = new Player;				// プレヤー	
	BackGroundManager* backGroundManager = new BackGroundManager(); // 背景管理	
	ObstacleManager*   obstacleManager   = new ObstacleManager();   // 障害物管理	
	Judge*             judge			 = new Judge();			    // 判定	
	UIManager*         uiManager		 = new UIManager();		    // UI管理
	Score*             scoreController	 = new Score();	            // 点数管理
	EffectController*  effectController	 = new EffectController();  // エフェクトコントローラー

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

		// シーンに合わせた処理
		switch (sceneController->GetNowScene())
		{
		case Tittle: // タイトルシーン

			// タイトル画面兼チュートリアル画面の表示
			
			/////////////////////////////////////
			// 更新処理呼び出し
			////////////////////////////////////
			// 4秒に一度背景オブジェクトの追加
			if (frameConter->GetFrame() % 240 == 0)
			{
				backGroundManager->CreateBackGroudObj(camera->GetPos().x);
			}
			// カメラ
			camera->Update(player);
			// プレイヤー
			player->Updata();
			// 背景管理者
			backGroundManager->Update(camera->GetPos().x);
			// 障害物管理者
			obstacleManager->Update(camera->GetPos().x);
			
			/////////////////////////////////////
			// 描画処理呼び出し
			////////////////////////////////////

			// 背景管理者
			backGroundManager->DrawGameScene();
			// プレイヤー
			player->Draw();
			// 障害物管理者
			obstacleManager->Draw();
			// UI管理
			uiManager->DrawTittleSece();

			// S入力でゲームシーンへ
			if (CheckHitKey(KEY_INPUT_S))
			{
				sceneController->ChangeNextScene(); // シーン切り替え
				frameConter->Initialize();			// フレーム初期化
			}

			break;
		case Game: // ゲームシーン			
			/////////////////////////////////////
			// 更新処理呼び出し
			////////////////////////////////////

			// 4秒に一度背景オブジェクトの追加
			if (frameConter->GetFrame() % 240 == 0)
			{
				backGroundManager->CreateBackGroudObj(camera->GetPos().x);
			}

			// スタートフラグがたち4秒に一回障害物追加
			if (frameConter->GetFrame() % 240 == 0 && gameStartFlg)
			{
				obstacleManager->CreateObstacleObject(camera->GetPos().x);
			}

			// カメラ
			camera->Update(player);
			// プレイヤー
			player->Updata();
			// 背景管理者
			backGroundManager->Update(camera->GetPos().x);
			// 障害物管理者
			obstacleManager->Update(camera->GetPos().x);
			// 衝突判定
			judge->Update(player, obstacleManager, scoreController, effectController, frameConter->GetFrame());
			// エフェクトコントローラー
			effectController->Update(frameConter->GetFrame());

			/////////////////////////////////////
			// 描画処理呼び出し
			////////////////////////////////////
						
			// 背景管理者
			backGroundManager->DrawGameScene();
			// プレイヤー
			player->Draw();
			// 障害物管理者
			obstacleManager->Draw();
			// UI
			uiManager->DrawGameScene(judge->GetIsAvoidanceSuccess(), scoreController->GetScore(),player->GetLifeNum());
			// エフェクト
			effectController->Draw();
			// ゲーム開始までのカウントダウン
			if (!gameStartFlg)
			{
				gameStartFlg = uiManager->Draw3CountDown(frameConter->GetFrame()); // カウント終了後trueが帰る
			}

			// プレイヤーの残機0でリザルトへ
			if (player->GetLifeNum() == 0)
			{
				sceneController->ChangeNextScene(); // シーン切り替え
				frameConter->Initialize();			// フレーム初期化
			}

			break;
		case Result: // リザルトシーン
			/////////////////////////////////////
			// 描画処理呼び出し
			////////////////////////////////////

			// 背景管理者
			backGroundManager->DrawResultScene();
			// UI
			uiManager->DrawResultScene(scoreController->GetScore());

			break;
		default:
			break;
		}				

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		//60FPS待ち
		while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
		{
			;
		}

		prevCount = nowCount;
		//フレームカウント増加
		frameConter->Update();
	}

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}