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
private:
	vector<Obstacle*> obstacleObjects; // 障害物オブジェクトのコンテナ	
};

