#include "Judge.h"

Judge::Judge()
{
	isAvoidanceSuccess = false;
	avoidanceSuccessFrame = 0;
}

Judge::~Judge()
{

}

/// <summary>
/// �Փ˔���
/// </summary>
/// <param name="ply">�v���C���[�N���X</param>
/// <param name="obstacleObjects">��Q��</param>
/// <param name="scoreCntroller">�X�R�A�Ǘ�</param>
void Judge::Update(Player* ply, ObstacleManager* obstacleManager, Score* scoreCntroller, EffectController* effectContoroller, int fps)
{
	// ��𐬌�������0.5�b�o�߂Ńt���O������
	if (fps == avoidanceSuccessFrame + 30 && isAvoidanceSuccess)
	{
		isAvoidanceSuccess = false;
	}

	// ��Q���I�u�W�F�N�g�̃R���e�i�擾
	vector<Obstacle*> obstacleObjects = obstacleManager->GetObstacleObject();

	// �v���C���[�Ə�Q���̏Փ˔���
	for (int i = 0; i < obstacleObjects.size(); i++)
	{
		// �O�����̒藝�ŏՓ˔���
		if (sqrt(pow(obstacleObjects[i]->GetColliderPos().x - ply->GetColliderPos().x, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().y - ply->GetColliderPos().y, 2)
			+ pow(obstacleObjects[i]->GetColliderPos().z - ply->GetColliderPos().z, 2))
			< ply->GetColliderRadius() + obstacleObjects[i]->GetColliderRadius())
		{
			// �Փˏ���
			ply->Damage();						           // �v���C���[�̃_���[�W����
			obstacleManager->DeleteObstacleObject(i);      // ��Q���I�u�W�F�N�g�̍폜
			effectContoroller->SetIsPlayDamageEffect(true); // �_���[�W�G�t�F�N�g�̍Đ��t���O�𗧂Ă�
			return;
		}
	}

	// ��Q�����悯���ۂ̉��Z����
	for (int i = 0; i < obstacleObjects.size(); i++)
	{
		// ��Q�����v���C���[�𒴂����ۂɓ��_�̉��Z����
		if (obstacleObjects[i]->GetPos().x < ply->GetPos().x - ply->GetColliderRadius() && !obstacleObjects[i]->GetIsPassing())
		{
			obstacleObjects[i]->SetIsPassing(true); // �ʉ߃t���O�𗧂Ă�
			scoreCntroller->AddSocre();  // �_���̉��Z����
			isAvoidanceSuccess = true;   // ��𐬌��t���O�𗧂Ă�
			avoidanceSuccessFrame = fps; // �������̃t���[�����ݒ�
		}
	}
}