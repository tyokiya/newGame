#pragma once
#include "DxLib.h"
#include "vector"
#include "Obstacle.h"

class Obstacle;
using namespace std;

/// <summary>
/// ��Q���Ǘ��N���X
/// </summary>
class ObstacleManager
{
public:
	ObstacleManager();
	~ObstacleManager();
private:
	vector<Obstacle*> obstacleObjects; // ��Q���I�u�W�F�N�g�̃R���e�i
};

