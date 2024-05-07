#pragma once
#include "DxLib.h"
#include "Collider.h"

// 定数
const float ObstacleSizeScale = 0.1f;                        // モデルの圧縮値
const float ObstacleColliderRadius = 8.0f;                   // 当たり判定半径
const float ObstacleCameraDirectionX = 350.0f;               // 生成時のx軸のカメラとの距離
const float InitializePosY = 3.0f;                           // 初期座標Y
const VECTOR ObstacleCorrectionColliderPos = VGet(0, 10, 0); // 中心座標を出す際の修正値

/// <summary>
/// 障害物クラス
/// </summary>
class Obstacle
{
public:
	Obstacle(float cameraPosX);         // コンストラクタ
	~Obstacle();                        // デストラクタ
	bool Update(float cameraPosX);      // 更新処理
	void Draw();						// 描画
	VECTOR GetPos() const { return pos; };
private:
	Collider* collider;                 // 判定クラス
	int	modelHandle;					// モデルハンドル
	VECTOR pos;							// 座標
};