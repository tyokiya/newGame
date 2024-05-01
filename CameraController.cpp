#include "CameraController.h"

CameraController::CameraController()
{
	// 値の初期化
	pos = InitializeCameraPos;
	lookAtPos = InitializeCameraLookAtPos;
	
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);
	//(90, 50, 20)の視点から(0, 45, 40)のターゲットを見る角度にカメラを設置
	SetCameraPositionAndTarget_UpVecY(pos, lookAtPos);
}

CameraController::~CameraController()
{
}

void CameraController::Update(const Player* player)
{
	// プレイヤーのx軸の移動量を計算
	float movementPlayerX = player->GetPos().x - player->GetVergePos().x;

	// プレイヤーの移動量だけカメラの注視点と座標移動
	pos.x += movementPlayerX;
	lookAtPos.x += movementPlayerX;

	// 移動量をカメラに反映
	SetCameraPositionAndTarget_UpVecY(pos, lookAtPos);
}