#include "ObstacleManager.h"

ObstacleManager::ObstacleManager()
{

}

ObstacleManager::~ObstacleManager()
{
    // ��Q���I�u�W�F�N�g�N���X�̃R���e�i�J��
    DeleteAllObstacleObject();
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
            DeleteObstacleObject(i);
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

/// <summary>
/// �w�肵����Q���I�u�W�F�N�g�̍폜
/// </summary>
/// <param name="index">�폜����I�u�W�F�N�g�̗v�f��</param>
void ObstacleManager::DeleteObstacleObject(int index)
{
    delete(obstacleObjects[index]);
    obstacleObjects.erase(obstacleObjects.begin());
}

/// <summary>
/// ���ׂĂ̏�Q���I�u�W�F�N�g�̍폜
/// </summary>
void ObstacleManager::DeleteAllObstacleObject()
{
    for (int i = 0; i < obstacleObjects.size(); i++)
    {
        DeleteObstacleObject(i);
    }
}