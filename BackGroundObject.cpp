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
    pos = BackGroundObjInitializePos;
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

/// <summary>
/// 更新処理
/// </summary>
/// <param name="cameraPosX"></param>
/// <returns>オブジェクトの削除フラグ</returns>
bool BackGroundObj::Update(float cameraPosX)
{
    // カメラから一定値以上離れたら削除処理
    if (cameraPosX - CameraDirectionX > pos.x )
    {
        // オブジェクトの削除フラグを返す
        return true;
    }
    return false;
}