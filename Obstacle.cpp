#include "Obstacle.h"

Obstacle::Obstacle(float cameraPosX)
{
	// 3D���f���̓ǂݍ���
	modelHandle = MV1LoadModel("Model/Obstacles/Bee.mv1");
	// 3D���f���̈��k
	MV1SetScale(modelHandle, VGet(ObstacleSizeScale, ObstacleSizeScale, ObstacleSizeScale));
	// ��]�l���Z�b�g
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, 89.5f, 0.0f));
	// �J�����̍��W�����ɏ�Q���̍��W�Z�b�g
	float setPosX = cameraPosX + ObstacleCameraDirectionX;
	pos = VGet(setPosX, InitializePosY, 0.0f);
	MV1SetPosition(modelHandle, pos);	
	// ����N���X������
	collider = new Collider(ObstacleColliderRadius, VAdd(pos,ObstacleCorrectionColliderPos)); // ��Q���̍��W�����S�łȂ������ɂ��邽�ߏC���l�𑫂�
	// �t���O������
	isPassing = false;
}

Obstacle::~Obstacle()
{

}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="cameraPosX"></param>
/// <returns>�I�u�W�F�N�g�̍폜�t���O</returns>
bool Obstacle::Update(float cameraPosX)
{
	// �J����������l�ȏ㗣�ꂽ��폜����
	if (cameraPosX - ObstacleDeleteCameraDirectionX > pos.x)
	{
		// �I�u�W�F�N�g�̍폜�t���O��Ԃ�
		return true;
	}
	return false;
}

void Obstacle::Draw()
{
	// �`��
	MV1DrawModel(modelHandle);
	// �e�X�g�p����`��
	collider->DrawCollider();
}