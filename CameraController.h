#pragma once
#include "DxLib.h"
#include "Player.h"

const VECTOR InitializeCameraPos = VGet(0, 50, -80);       // 初期座標
const VECTOR InitializeCameraLookAtPos = VGet(0, 45, 0);   // 初期注視点

/// <summary>
/// カメラのコントローラークラス
/// </summary>
class CameraController
{
public:
	CameraController();
	~CameraController();
	void Update(const Player* player);
private:
	VECTOR lookAtPos; // 注視点
	VECTOR pos;       // 座標
};

