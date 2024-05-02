#pragma once
#include "DxLib.h"
#include "Collider.h"

const float ObstacleSizeScale = 0.2f;                // モデルの圧縮値
const float ColliderRadius = 8.0f;                   // 当たり判定半径
const float CameraDirectionX = 350.0f;               // 生成時のx軸のカメラとの距離
const VECTOR CorrectionColliderPos = VGet(0, 17, 0); // 中心座標を出す際の修正値

/// <summary>
/// 障害物クラス
/// </summary>
class Obstacle
{
public:
	Obstacle(float cameraPosX);                         // コンストラクタ
	~Obstacle();                        // デストラクタ
	void Draw();						// 描画
	VECTOR GetPos() const { return pos; };
private:
	Collider* collider;                 // 判定クラス
	int	modelHandle;					// モデルハンドル
	VECTOR pos;							// 座標
};