#include "Judge.h"

Judge::Judge()
{

}

Judge::~Judge()
{

}

/// <summary>
/// �Փ˔���
/// </summary>
/// <param name="ply">�v���C���[�N���X</param>
/// <param name="obstacleObjects">��Q��</param>
void Judge::JudgeCollision(Player* ply, ObstacleManager* obstacleManager)
{
	// ��Q���I�u�W�F�N�g�̃R���e�i�擾
	vector<Obstacle*> obstacleObjects = obstacleManager->GetObstacleObject();

	for (int i = 0; i < obstacleObjects.size(); i++)
	{
		//�O�����̒藝�ŏՓ˔���
		if (sqrt(pow(obstacleObjects[i]->GetColliderPos().x - ply->GetColliderPos().x, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().y - ply->GetColliderPos().y, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().z - ply->GetColliderPos().z, 2))
			< ply->GetColliderRadius() + obstacleObjects[i]->GetColliderRadius())
		{
			// �Փˏ���
			ply->Damage();						      // �v���C���[�̃_���[�W����
			obstacleManager->DeleteObstacleObject(i); // ��Q���I�u�W�F�N�g�̍폜
		}
	}
	
}