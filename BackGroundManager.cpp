#include "BackGroundManager.h"

BackGroundManager::BackGroundManager()
{
}

BackGroundManager::~BackGroundManager()
{
}

/// <summary>
/// 背景オブジェクトの生成
/// </summary>
/// <param name="cameraPosX">カメラの座標x</param>
void BackGroundManager::CreateBackGroudObj(float cameraPosX)
{

}

void BackGroundManager::Update()
{
    // コンテナ内のオブジェクトの更新処理呼び出し
    for (int i = 0; i < BackGoundObjects.size(); i++)
    {
        BackGoundObjects[i].Update();
    }
}

void BackGroundManager::Draw()
{
    // コンテナ内のオブジェクトの描画処理呼び出し
    for (int i = 0; i < BackGoundObjects.size(); i++)
    {
        BackGoundObjects[i].Draw();
    }
}