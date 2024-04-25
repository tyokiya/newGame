#pragma once
#include "DxLib.h"

const float CameraDirectionX = 200.0f; // ��������x���̃J�����Ƃ̋���

/// <summary>
/// �w�i�I�u�W�F�N�g�̃N���X
/// </summary>
class BackGroundObj
{
public:
	BackGroundObj(const char* modelPass, float compressionValue);    // �R���X�g���N�^
	~BackGroundObj();              // �f�X�g���N�^
	void SetPos(float cameraPosX); // ���W�ݒ�
	void Update();                 // �X�V����
	void Draw();		           // �`��
private:
	int	modelHandle;	// ���f���n���h��
	VECTOR pos;			// ���W
};