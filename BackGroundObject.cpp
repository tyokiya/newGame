#include"BackGroundObject.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="filePass">モデルのファイルパス</param>
/// <param name="compressionValue>圧縮地</param>
BackGroundObj::BackGroundObj(const char* modelPass, float compressionValue)
{
    modelHandle = MV1LoadModel(modelPass);
    // モデルの圧縮
    MV1SetScale(modelHandle, VGet(compressionValue, compressionValue, compressionValue));
    // 初期座標のセット
    pos = VGet(0.0f, 0.0f, 80.0f);
}

BackGroundObj::~BackGroundObj()
{
    MV1DeleteModel(modelHandle);
}

void BackGroundObj::SetPos(float cameraPosX)
{
    // カメラとの距離を一定値離した位置に座標設定
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