#pragma once
#include "DxLib.h"

const float CameraDirectionX = 350.0f;                              // ��������x���̃J�����Ƃ̋���
const VECTOR BackGroundObjInitializePos = VGet(0.0f, 0.0f, 150.0f); // �w�i�I�u�W�F�N�g�̏������W

/// <summary>
/// �w�i�I�u�W�F�N�g�̃N���X
/// </summary>
class BackGroundObj
{
public:
	BackGroundObj(const char* modelPass, float compressionValue);    // �R���X�g���N�^
	~BackGroundObj();              // �f�X�g���N�^
	void SetPos(float cameraPosX); // ���W�ݒ�
	bool Update(float cameraPosX); // �X�V����
	void Draw();		           // �`��
private:
	int	modelHandle;	// ���f���n���h��
	VECTOR pos;			// ���W
};