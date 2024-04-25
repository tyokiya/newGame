#include "CameraController.h"

CameraController::CameraController()
{
	// �l�̏�����
	pos = InitializeCameraPos;
	lookAtPos = InitializeCameraLookAtPos;
	
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1000.0f);
	//(90, 50, 20)�̎��_����(0, 45, 40)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(pos, lookAtPos);
}

CameraController::~CameraController()
{
}

void CameraController::Update(const Player* player)
{
	// �v���C���[��x���̈ړ��ʂ��v�Z
	float movementPlayerX = player->GetPos().x - player->GetVergePos().x;

	// �v���C���[�̈ړ��ʂ����J�����̒����_�ƍ��W�ړ�
	pos.x += movementPlayerX;
	lookAtPos.x += movementPlayerX;

	// �ړ��ʂ��J�����ɔ��f
	SetCameraPositionAndTarget_UpVecY(pos, lookAtPos);
}