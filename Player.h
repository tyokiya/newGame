#pragma once
#include "DxLib.h"
#include "Collider.h"

const VECTOR InitializePos = VGet(-55, 0, 0);
const int InitializeLifeNum = 2;	  // 初期ライフ数
const float PlayerSizeScale = 0.2f;   // プレイヤーの圧縮値
const float AddJumpForce = 3.0f;      // ジャンプ力
const float Gravity = 0.1f;			  // 重力
const float RunSpeed = 2.0f;          // 走る速度
const float ColliderRadius = 8.0f;    // 当たり判定半径
const VECTOR CorrectionColliderPos = VGet(0,17,0); // 中心座標を出す際の修正値

/// <summary>
/// プレイヤークラス
/// </summary>
class Player
{
public:
	Player();                           // コンストラクタ
	~Player();                          // デストラクタ
	void Updata();                      // 更新処理
	void Draw();						// 描画
	void Damage();                      // ダメージ処理
	VECTOR GetVergePos() const { return vergePos; };
	VECTOR GetPos() const { return pos; };
	VECTOR GetColliderPos() const { return collider->GetCenterPos(); };
	float GetColliderRadius() const { return collider->GetColliderRasius(); };
	int GetLifeNum()const { return life; };
private:
	Collider* collider;                 // 判定クラス
	int	modelHandle;					// モデルハンドル
	VECTOR pos;							// プレイヤーの座標
	VECTOR vergePos;                    // 1フレ前の座標
	bool isJump = false;                // ジャンプフラグ
	float nowJumpForce;                 // 現在のジャンプ力
	int life;							// 残機
};
