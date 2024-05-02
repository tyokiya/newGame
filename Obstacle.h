#pragma once
#include "DxLib.h"
#include "Collider.h"

const float ObstacleSizeScale = 0.2f;                // ���f���̈��k�l
const float ColliderRadius = 8.0f;                   // �����蔻�蔼�a
const float CameraDirectionX = 350.0f;               // ��������x���̃J�����Ƃ̋���
const VECTOR CorrectionColliderPos = VGet(0, 17, 0); // ���S���W���o���ۂ̏C���l

/// <summary>
/// ��Q���N���X
/// </summary>
class Obstacle
{
public:
	Obstacle(float cameraPosX);                         // �R���X�g���N�^
	~Obstacle();                        // �f�X�g���N�^
	void Draw();						// �`��
	VECTOR GetPos() const { return pos; };
private:
	Collider* collider;                 // ����N���X
	int	modelHandle;					// ���f���n���h��
	VECTOR pos;							// ���W
};