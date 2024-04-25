#pragma once
#include "DxLib.h"

const float PlayerSizeScale = 0.2f;   // プレイヤーの圧縮地
const float AddJumpForce = 3.0f;      // ジャンプ力
const float Gravity = 0.1f;			  // 重力

//プレイヤークラス
class Player
{
private:
	int	modelHandle;					// モデルハンドル
	VECTOR pos;							// プレイヤーの座標
	bool isJump = false;                // ジャンプフラグ
	float nowJumpForce;                 // 現在のジャンプ力
public:
	Player();                           // コンストラクタ
	~Player();                          // デストラクタ
	void Updata();                      // 更新処理
	void Draw();						// 描画
};
