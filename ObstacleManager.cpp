#include "ObstacleManager.h"

ObstacleManager::ObstacleManager()
{

}

ObstacleManager::~ObstacleManager()
{

}

/// <summary>
/// ��Q���I�u�W�F�N�g�̐���
/// </summary>
/// <param name="cameraPosX">�J�����̍��Wx</param>
void ObstacleManager::CreateObstacleObject(float cameraPosX)
{
    // �N���X�錾
    Obstacle* obstacle = new Obstacle(cameraPosX);
    // �I�u�W�F�N�g���R���e�i�ɒǉ�
    obstacleObjects.push_back(obstacle);
}

/// <summary>
/// ��Q���I�u�W�F�N�g�̍X�V
/// </summary>
/// <param name="cameraPosX">�J�����̍��WX</param>
void ObstacleManager::Update(float cameraPosX)
{
    // �R���e�i���̃I�u�W�F�N�g�̍X�V�����Ăяo��
    for (int i = 0; i < obstacleObjects.size(); i++)
    {
        bool destroyFlg = obstacleObjects[i]->Update(cameraPosX);
        // �I�u�W�F�N�g�̍폜�t���O���A���Ă����烁�������
        if (destroyFlg)
        {
            delete(obstacleObjects[i]);
            obstacleObjects.erase(obstacleObjects.begin());
        }
    }
}

void ObstacleManager::Draw()
{
    // �R���e�i���̃I�u�W�F�N�g�̕`�揈���Ăяo��
    for (int i = 0; i < obstacleObjects.size(); i++)
    {
        obstacleObjects[i]->Draw();
    }
}