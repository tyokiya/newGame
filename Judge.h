#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleManager.h"
#include "UImanager.h"
#include "Score.h"
#include "FrameCounter.h"
#include "vector"

using namespace std;

/// <summary>
/// 判定クラス
/// </summary>
class Judge
{
public:
	Judge();
	~Judge();
	void Update(Player* ply, ObstacleManager* obstacleManager, Score* scoreCntroller, int fps); // 衝突判定
	bool GetIsAvoidanceSuccess()const { return isAvoidanceSuccess; }; // 回避成功フラグを返す
private:
	bool isAvoidanceSuccess;	     // 回避成功フラグ
	int avoidanceSuccessFrame;       // 回避成功時のフレーム
};