#pragma once
#include "DxLib.h"

const float PlayerSizeScale = 0.2f;

//プレイヤークラス
class Player
{
private:
	int	modelHandle;					// モデルハンドル
	VECTOR pos;							// プレイヤーの座標
	bool JumpFlg = false;               // ジャンプフラグ
public:
	Player();                           // コンストラクタ
	~Player();                          // デストラクタ
	void Updata();                      // 更新処理
	void Draw();						// 描画
};
