#pragma once
#include "DxLib.h"
#include "vector"
#include "Obstacle.h"

class Obstacle;
using namespace std;

/// <summary>
/// 障害物管理クラス
/// </summary>
class ObstacleManager
{
public:
	ObstacleManager();
	~ObstacleManager();
	void CreateObstacleObject(float cameraPosX); // 障害物オブジェクト生成
	void Update(float cameraPosX);
	void Draw();
	void DeleteObstacleObject(int index);		 // 指定した障害物オブジェクトの削除
	void DeleteAllObstacleObject();			     // すべての障害物オブジェクトの削除
	vector<Obstacle*> GetObstacleObject()const { return obstacleObjects; };
private:
	vector<Obstacle*> obstacleObjects; // 障害物オブジェクトのコンテナ	
};

