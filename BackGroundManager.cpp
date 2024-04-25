#include "BackGroundManager.h"

BackGroundManager::BackGroundManager()
{
    //�w�i�摜�Ǎ���
    BackImgHandle = LoadGraph("IMG/Gras.jpg");
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
    // �����_���ɔw�i�I�u�W�F�N�g�̐���
    int randNum = GetRand(1);
    // �I�u�W�F�N�g����
    switch (randNum)
    {
    case 0:
    {
        // �N���X�錾
        BackGroundObj* backGround = new BackGroundObj("Model/BackGround/House.mv1", 0.1f);
        // ���W�ݒ�
        backGround->SetPos(cameraPosX);
        // �I�u�W�F�N�g���R���e�i�ɒǉ�
        backGoundObjects.push_back(backGround);
        break;
    }        
    case 1:
    {
        BackGroundObj* backGround = new BackGroundObj("Model/BackGround/House2.mv1", 0.05f);
        backGround->SetPos(cameraPosX);
        backGoundObjects.push_back(backGround);
        break;
    }        
    default:
        break;
    }
}

void BackGroundManager::Update()
{
    // �R���e�i���̃I�u�W�F�N�g�̍X�V�����Ăяo��
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        backGoundObjects[i]->Update();
    }
}

void BackGroundManager::Draw()
{
    DrawExtendGraph(0, 0, 1200, 800, BackImgHandle, true);
    // �R���e�i���̃I�u�W�F�N�g�̕`�揈���Ăяo��
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        backGoundObjects[i]->Draw();
    }
}