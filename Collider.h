#pragma once
#include "DxLib.h"

/// <summary>
/// 当たり判定クラス
/// </summary>
class Collider
{
public:
	Collider(float colliderRadius,VECTOR centorPos);            // コンストラクタ
	~Collider();                                                // デストラクタ
	void UpdatePos(VECTOR setPos);                              // 座標更新
	VECTOR GetCenterPos()const { return centerPos; };           // 座標ゲッター
	float  GetColliderRasius()const { return colliderRadius; }; // 半径ゲッター
	bool GetisHit()const { return isHit; };                     // 衝突フラグゲッター
	void DrawCollider();                                        // 判定の描画(テスト用)
private:
	VECTOR centerPos;     // 当たり判定球の中心座標
	float colliderRadius; // 当たり判定球の半径
	bool isHit;           // 衝突フラグ	
};