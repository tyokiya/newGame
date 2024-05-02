#include "Obstacle.h"

Obstacle::Obstacle(float cameraPosX)
{
	// 3Dモデルの読み込み
	modelHandle = MV1LoadModel("Model/Obstacle/Bee.mv1");
	// 3Dモデルの圧縮
	MV1SetScale(modelHandle, VGet(ObstacleSizeScale, ObstacleSizeScale, ObstacleSizeScale));
	// カメラの座標を下に障害物の座標セット
	float setPosX = cameraPosX + CameraDirectionX;
	pos = VGet(setPosX, 0.0f, 0.0f);
	// 判定クラス初期化
	collider = new Collider(ColliderRadius, VAdd(pos, CorrectionColliderPos)); // プレイヤーの座標が中心でなく足元にあるため修正値を足す
}

Obstacle::~Obstacle()
{

}

void Obstacle::Draw()
{
	// プレイヤーの描画
	MV1DrawModel(modelHandle);
	// テスト用判定描画
	collider->DrawCollider();
}