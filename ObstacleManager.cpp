#include "ObstacleManager.h"

ObstacleManager::ObstacleManager()
{

}

ObstacleManager::~ObstacleManager()
{
    // 障害物オブジェクトクラスのコンテナ開放
    DeleteAllObstacleObject();
}

/// <summary>
/// 障害物オブジェクトの生成
/// </summary>
/// <param name="cameraPosX">カメラの座標x</param>
void ObstacleManager::CreateObstacleObject(float cameraPosX)
{
    // クラス宣言
    Obstacle* obstacle = new Obstacle(cameraPosX);
    // オブジェクトをコンテナに追加
    obstacleObjects.push_back(obstacle);
}

/// <summary>
/// 障害物オブジェクトの更新
/// </summary>
/// <param name="cameraPosX">カメラの座標X</param>
void ObstacleManager::Update(float cameraPosX)
{
    // コンテナ内のオブジェクトの更新処理呼び出し
    for (int i = 0; i < obstacleObjects.size(); i++)
    {
        bool destroyFlg = obstacleObjects[i]->Update(cameraPosX);
        // オブジェクトの削除フラグが帰ってきたらメモリ解放
        if (destroyFlg)
        {
            DeleteObstacleObject(i);
        }
    }
}

void ObstacleManager::Draw()
{
    // コンテナ内のオブジェクトの描画処理呼び出し
    for (int i = 0; i < obstacleObjects.size(); i++)
    {
        obstacleObjects[i]->Draw();
    }
}

/// <summary>
/// 指定した障害物オブジェクトの削除
/// </summary>
/// <param name="index">削除するオブジェクトの要素数</param>
void ObstacleManager::DeleteObstacleObject(int index)
{
    delete(obstacleObjects[index]);
    obstacleObjects.erase(obstacleObjects.begin());
}

/// <summary>
/// すべての障害物オブジェクトの削除
/// </summary>
void ObstacleManager::DeleteAllObstacleObject()
{
    for (int i = 0; i < obstacleObjects.size(); i++)
    {
        DeleteObstacleObject(i);
    }
}