#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleManager.h"
#include "vector"

using namespace std;

/// <summary>
/// ����N���X
/// </summary>
class Judge
{
public:
	Judge();
	~Judge();
	void JudgeCollision(Player* ply, ObstacleManager* obstacleManager); // �Փ˔���
};