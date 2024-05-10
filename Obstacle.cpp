#include "Obstacle.h"

Obstacle::Obstacle(float cameraPosX)
{
	// 3Dモデルの読み込み
	modelHandle = MV1LoadModel("Model/Obstacles/Bee.mv1");
	// 3Dモデルの圧縮
	MV1SetScale(modelHandle, VGet(ObstacleSizeScale, ObstacleSizeScale, ObstacleSizeScale));
	// 回転値をセット
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, 89.5f, 0.0f));
	// カメラの座標を下に障害物の座標セット
	float setPosX = cameraPosX + ObstacleCameraDirectionX;
	pos = VGet(setPosX, InitializePosY, 0.0f);
	MV1SetPosition(modelHandle, pos);	
	// 判定クラス初期化
	collider = new Collider(ObstacleColliderRadius, VAdd(pos,ObstacleCorrectionColliderPos)); // 障害物の座標が中心でなく足元にあるため修正値を足す
	// フラグ初期化
	isPassing = false;
}

Obstacle::~Obstacle()
{

}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="cameraPosX"></param>
/// <returns>オブジェクトの削除フラグ</returns>
bool Obstacle::Update(float cameraPosX)
{
	// カメラから一定値以上離れたら削除処理
	if (cameraPosX - ObstacleDeleteCameraDirectionX > pos.x)
	{
		// オブジェクトの削除フラグを返す
		return true;
	}
	return false;
}

void Obstacle::Draw()
{
	// 描画
	MV1DrawModel(modelHandle);
	// テスト用判定描画
	collider->DrawCollider();
}