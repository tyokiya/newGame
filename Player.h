#pragma once
#include "DxLib.h"

//プレイヤークラス
class Player
{
private:
	int	modelHandle;					//モデルハンドル
	VECTOR pos;							//プレイヤーの座標
public:
	Player();                           // コンストラクタ
	~Player();                          // デストラクタ
	void Updata();                      // 更新処理
	void Draw();						// 描画
};
