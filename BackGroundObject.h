#pragma once
#include "DxLib.h"

/// <summary>
/// �w�i�I�u�W�F�N�g�̃N���X
/// </summary>
class BackGroundObj
{
public:
	BackGroundObj(const char* modelPass);    // �R���X�g���N�^
	~BackGroundObj();   // �f�X�g���N�^
	void Update();      // �X�V����
	void Draw();		// �`��
private:
	int	modelHandle;	// ���f���n���h��
	VECTOR pos;			// ���W
};