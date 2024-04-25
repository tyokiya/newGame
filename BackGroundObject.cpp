#include"BackGroundObject.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="filePass">���f���̃t�@�C���p�X</param>
BackGroundObj::BackGroundObj(const char* modelPass)
{
    modelHandle = MV1LoadModel(modelPass);
    //���W�̃Z�b�g
    pos = VGet(0.0f, 0.0f, 1.0f);
}

BackGroundObj::~BackGroundObj()
{
    MV1DeleteModel(modelHandle);
}

void BackGroundObj::Draw()
{
    MV1DrawModel(modelHandle);
}

void BackGroundObj::Update()
{

}