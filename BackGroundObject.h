#pragma once
#include "DxLib.h"

const float CameraDirectionX = 200.0f; // 生成時のx軸のカメラとの距離

/// <summary>
/// 背景オブジェクトのクラス
/// </summary>
class BackGroundObj
{
public:
	BackGroundObj(const char* modelPass, float compressionValue);    // コンストラクタ
	~BackGroundObj();              // デストラクタ
	void SetPos(float cameraPosX); // 座標設定
	void Update();                 // 更新処理
	void Draw();		           // 描画
private:
	int	modelHandle;	// モデルハンドル
	VECTOR pos;			// 座標
};