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
private:
	vector<Obstacle*> obstacleObjects; // 障害物オブジェクトのコンテナ
};

