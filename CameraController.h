#pragma once
#include "DxLib.h"
#include "Player.h"

const VECTOR InitializeCameraPos = VGet(0, 50, -80);       // �������W
const VECTOR InitializeCameraLookAtPos = VGet(0, 45, 0);   // ���������_

/// <summary>
/// �J�����̃R���g���[���[�N���X
/// </summary>
class CameraController
{
public:
	CameraController();
	~CameraController();
	void Update(const Player* player);
private:
	VECTOR lookAtPos; // �����_
	VECTOR pos;       // ���W
};

