#include "BackGroundManager.h"

BackGroundManager::BackGroundManager()
{
    //背景画像読込み
    GroudImgHandle = LoadGraph("IMG/Ground.jpg");
    SkyImgHandle = LoadGraph("IMG/Sky.jpg");
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
        BackGroundObj* backGround = new BackGroundObj("Model/BackGround/House.mv1", HouseSizeScale);
        // 座標設定
        backGround->SetPos(cameraPosX);
        // オブジェクトをコンテナに追加
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
    // コンテナ内のオブジェクトの更新処理呼び出し
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        bool destroyFlg = backGoundObjects[i]->Update(cameraPosX);
        // オブジェクトの削除フラグが帰ってきたらメモリ解放
        if (destroyFlg)
        {
            delete(backGoundObjects[i]);
            backGoundObjects.erase(backGoundObjects.begin());
        }        
    }
}

void BackGroundManager::DrawGameScene()
{
    // 背景描画    
    DrawExtendGraph(0, 0, 1200, 800, GroudImgHandle, true); // 地面
    DrawExtendGraph(0, 0, 1200, 450, SkyImgHandle, true);   // 空
    // コンテナ内のオブジェクトの描画処理呼び出し
    for (int i = 0; i < backGoundObjects.size(); i++)
    {
        backGoundObjects[i]->Draw();
    }
}

void BackGroundManager::DrawResultScene()
{
    // 背景描画    
    DrawExtendGraph(0, 0, 1200, 800, GroudImgHandle, true); // 地面
    DrawExtendGraph(0, 0, 1200, 450, SkyImgHandle, true);   // 空
}