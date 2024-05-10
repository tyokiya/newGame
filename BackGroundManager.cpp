#include "BackGroundManager.h"

BackGroundManager::BackGroundManager()
{
    //�w�i�摜�Ǎ���
    GroudImgHandle = LoadGraph("IMG/Ground.jpg");
    SkyImgHandle = LoadGraph("IMG/Sky.jpg");
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
        BackGroundObj* backGround = new BackGroundObj("Model/BackGround/House.mv1", HouseSizeScale);
        // ���W�ݒ�
        backGround->SetPos(cameraPosX);
        // �I�u�W�F�N�g���R���e�i�ɒǉ�
        backGoundObjects.push_back(backGround);
        break;
    }        
    case 1:
    {
        BackGroundObj* backGround = new BackGroundObj("Model/BackGround/House2.mv1", House2SizeScale);
        backGround->SetPos(cameraPosX);
        backGoundObjects.push_back(backGround);
        break;
    }        
    default:
        break;
    }
}

void BackGroundManager::Update(float cameraPosX)
{
    // �R���e�i���̃I�u�W�F�N�g�̍X�V�����Ăяo��
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        bool destroyFlg = backGoundObjects[i]->Update(cameraPosX);
        // �I�u�W�F�N�g�̍폜�t���O���A���Ă����烁�������
        if (destroyFlg)
        {
            delete(backGoundObjects[i]);
            backGoundObjects.erase(backGoundObjects.begin());
        }        
    }
}

void BackGroundManager::DrawGameScene()
{
    // �w�i�`��    
    DrawExtendGraph(0, 0, 1200, 800, GroudImgHandle, true); // �n��
    DrawExtendGraph(0, 0, 1200, 450, SkyImgHandle, true);   // ��
    // �R���e�i���̃I�u�W�F�N�g�̕`�揈���Ăяo��
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        backGoundObjects[i]->Draw();
    }
}

void BackGroundManager::DrawResultScene()
{
    // �w�i�`��    
    DrawExtendGraph(0, 0, 1200, 800, GroudImgHandle, true); // �n��
    DrawExtendGraph(0, 0, 1200, 450, SkyImgHandle, true);   // ��
}