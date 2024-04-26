#pragma once
#include "DxLib.h"

const float CameraDirectionX = 350.0f;                              // 生成時のx軸のカメラとの距離
const VECTOR BackGroundObjInitializePos = VGet(0.0f, 0.0f, 150.0f); // 背景オブジェクトの初期座標

/// <summary>
/// 背景オブジェクトのクラス
/// </summary>
class BackGroundObj
{
public:
	BackGroundObj(const char* modelPass, float compressionValue);    // コンストラクタ
	~BackGroundObj();              // デストラクタ
	void SetPos(float cameraPosX); // 座標設定
	bool Update(float cameraPosX); // 更新処理
	void Draw();		           // 描画
private:
	int	modelHandle;	// モデルハンドル
	VECTOR pos;			// 座標
};