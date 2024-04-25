#include"BackGroundObject.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="filePass">モデルのファイルパス</param>
BackGroundObj::BackGroundObj(const char* modelPass)
{
    modelHandle = MV1LoadModel(modelPass);
    //座標のセット
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