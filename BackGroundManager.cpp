#include "BackGroundManager.h"

BackGroundManager::BackGroundManager()
{
}

BackGroundManager::~BackGroundManager()
{
}

/// <summary>
/// �w�i�I�u�W�F�N�g�̐���
/// </summary>
/// <param name="cameraPosX">�J�����̍��Wx</param>
void BackGroundManager::CreateBackGroudObj(float cameraPosX)
{

}

void BackGroundManager::Update()
{
    // �R���e�i���̃I�u�W�F�N�g�̍X�V�����Ăяo��
    for (int i = 0; i < BackGoundObjects.size(); i++)
    {
        BackGoundObjects[i].Update();
    }
}

void BackGroundManager::Draw()
{
    // �R���e�i���̃I�u�W�F�N�g�̕`�揈���Ăяo��
    for (int i = 0; i < BackGoundObjects.size(); i++)
    {
        BackGoundObjects[i].Draw();
    }
}