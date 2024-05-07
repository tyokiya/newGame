#include "Judge.h"

Judge::Judge()
{

}

Judge::~Judge()
{

}

/// <summary>
/// 衝突判定
/// </summary>
/// <param name="ply">プレイヤークラス</param>
/// <param name="obstacleObjects">障害物</param>
void Judge::JudgeCollision(Player* ply, ObstacleManager* obstacleManager)
{
	// 障害物オブジェクトのコンテナ取得
	vector<Obstacle*> obstacleObjects = obstacleManager->GetObstacleObject();

	for (int i = 0; i < obstacleObjects.size(); i++)
	{
		//三平方の定理で衝突判定
		if (sqrt(pow(obstacleObjects[i]->GetColliderPos().x - ply->GetColliderPos().x, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().y - ply->GetColliderPos().y, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().z - ply->GetColliderPos().z, 2))
			< ply->GetColliderRadius() + obstacleObjects[i]->GetColliderRadius())
		{
			// 衝突処理
			ply->Damage();						      // プレイヤーのダメージ処理
			obstacleManager->DeleteObstacleObject(i); // 障害物オブジェクトの削除
		}
	}
	
}