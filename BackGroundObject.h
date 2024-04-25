#pragma once
#include "DxLib.h"

/// <summary>
/// 背景オブジェクトのクラス
/// </summary>
class BackGroundObj
{
public:
	BackGroundObj(const char* modelPass);    // コンストラクタ
	~BackGroundObj();   // デストラクタ
	void Update();      // 更新処理
	void Draw();		// 描画
private:
	int	modelHandle;	// モデルハンドル
	VECTOR pos;			// 座標
};