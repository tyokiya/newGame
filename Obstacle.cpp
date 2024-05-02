#include "Obstacle.h"

Obstacle::Obstacle(float cameraPosX)
{
	// 3D���f���̓ǂݍ���
	modelHandle = MV1LoadModel("Model/Obstacle/Bee.mv1");
	// 3D���f���̈��k
	MV1SetScale(modelHandle, VGet(ObstacleSizeScale, ObstacleSizeScale, ObstacleSizeScale));
	// �J�����̍��W�����ɏ�Q���̍��W�Z�b�g
	float setPosX = cameraPosX + CameraDirectionX;
	pos = VGet(setPosX, 0.0f, 0.0f);
	// ����N���X������
	collider = new Collider(ColliderRadius, VAdd(pos, CorrectionColliderPos)); // �v���C���[�̍��W�����S�łȂ������ɂ��邽�ߏC���l�𑫂�
}

Obstacle::~Obstacle()
{

}

void Obstacle::Draw()
{
	// �v���C���[�̕`��
	MV1DrawModel(modelHandle);
	// �e�X�g�p����`��
	collider->DrawCollider();
}