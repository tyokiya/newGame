#include "Judge.h"

Judge::Judge()
{
	isAvoidanceSuccess = false;
	avoidanceSuccessFrame = 0;
}

Judge::~Judge()
{

}

/// <summary>
/// 衝突判定
/// </summary>
/// <param name="ply">プレイヤークラス</param>
/// <param name="obstacleObjects">障害物</param>
/// <param name="scoreCntroller">スコア管理</param>
void Judge::Update(Player* ply, ObstacleManager* obstacleManager, Score* scoreCntroller, EffectController* effectContoroller, int fps)
{
	// 回避成功時から0.5秒経過でフラグを下す
	if (fps == avoidanceSuccessFrame + 30 && isAvoidanceSuccess)
	{
		isAvoidanceSuccess = false;
	}

	// 障害物オブジェクトのコンテナ取得
	vector<Obstacle*> obstacleObjects = obstacleManager->GetObstacleObject();

	// プレイヤーと障害物の衝突判定
	for (int i = 0; i < obstacleObjects.size(); i++)
	{
		// 三平方の定理で衝突判定
		if (sqrt(pow(obstacleObjects[i]->GetColliderPos().x - ply->GetColliderPos().x, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().y - ply->GetColliderPos().y, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().z - ply->GetColliderPos().z, 2))
			< ply->GetColliderRadius() + obstacleObjects[i]->GetColliderRadius())
		{
			// 衝突処理
			ply->Damage();						           // プレイヤーのダメージ処理
			obstacleManager->DeleteObstacleObject(i);      // 障害物オブジェクトの削除
			effectContoroller->SetIsPlayDamageEffect(true); // ダメージエフェクトの再生フラグを立てる
			return;
		}
	}

	// 障害物をよけた際の加算判定
	for (int i = 0; i < obstacleObjects.size(); i++)
	{
		// 障害物がプレイヤーを超えた際に得点の加算処理
		if (obstacleObjects[i]->GetPos().x < ply->GetPos().x - ply->GetColliderRadius() && !obstacleObjects[i]->GetIsPassing())
		{
			obstacleObjects[i]->SetIsPassing(true); // 通過フラグを立てる
			scoreCntroller->AddSocre();  // 点数の加算処理
			isAvoidanceSuccess = true;   // 回避成功フラグを立てる
			avoidanceSuccessFrame = fps; // 成功字のフレーム数設定
		}
	}
}