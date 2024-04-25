#include"BackGroundObject.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="filePass">���f���̃t�@�C���p�X</param>
/// <param name="compressionValue>���k�n</param>
BackGroundObj::BackGroundObj(const char* modelPass, float compressionValue)
{
    modelHandle = MV1LoadModel(modelPass);
    // ���f���̈��k
    MV1SetScale(modelHandle, VGet(compressionValue, compressionValue, compressionValue));
    // �������W�̃Z�b�g
    pos = VGet(0.0f, 0.0f, 80.0f);
}

BackGroundObj::~BackGroundObj()
{
    MV1DeleteModel(modelHandle);
}

void BackGroundObj::SetPos(float cameraPosX)
{
    // �J�����Ƃ̋��������l�������ʒu�ɍ��W�ݒ�
    pos.x = cameraPosX + CameraDirectionX;
    MV1SetPosition(modelHandle,pos);
}

void BackGroundObj::Draw()
{
    MV1DrawModel(modelHandle);
}

void BackGroundObj::Update()
{

}