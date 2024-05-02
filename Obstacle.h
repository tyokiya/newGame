#pragma once
#include "DxLib.h"
#include "Collider.h"

// �萔
const float ObstacleSizeScale = 0.1f;                        // ���f���̈��k�l
const float ObstacleColliderRadius = 8.0f;                   // �����蔻�蔼�a
const float ObstacleCameraDirectionX = 350.0f;               // ��������x���̃J�����Ƃ̋���
const float InitializePosY = 3.0f;                           // �������WY
const VECTOR ObstacleCorrectionColliderPos = VGet(0, 10, 0); // ���S���W���o���ۂ̏C���l

/// <summary>
/// ��Q���N���X
/// </summary>
class Obstacle
{
public:
	Obstacle(float cameraPosX);         // �R���X�g���N�^
	~Obstacle();                        // �f�X�g���N�^
	bool Update(float cameraPosX);      // �X�V����
	void Draw();						// �`��
	VECTOR GetPos() const { return pos; };
private:
	Collider* collider;                 // ����N���X
	int	modelHandle;					// ���f���n���h��
	VECTOR pos;							// ���W
};