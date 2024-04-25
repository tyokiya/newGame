#include "BackGroundManager.h"

BackGroundManager::BackGroundManager()
{
    //背景画像読込み
    BackImgHandle = LoadGraph("IMG/Gras.jpg");
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
    // ランダムに背景オブジェクトの生成
    int randNum = GetRand(1);
    // オブジェクト生成
    switch (randNum)
    {
    case 0:
    {
        // クラス宣言
        BackGroundObj* backGround = new BackGroundObj("Model/BackGround/House.mv1", 0.1f);
        // 座標設定
        backGround->SetPos(cameraPosX);
        // オブジェクトをコンテナに追加
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
    // コンテナ内のオブジェクトの更新処理呼び出し
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        backGoundObjects[i]->Update();
    }
}

void BackGroundManager::Draw()
{
    DrawExtendGraph(0, 0, 1200, 800, BackImgHandle, true);
    // コンテナ内のオブジェクトの描画処理呼び出し
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        backGoundObjects[i]->Draw();
    }
}