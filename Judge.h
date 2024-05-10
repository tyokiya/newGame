#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleManager.h"
#include "UImanager.h"
#include "Score.h"
#include "FrameCounter.h"
#include "EffectController.h"
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
	void Update(Player* ply, ObstacleManager* obstacleManager, Score* scoreCntroller, EffectController* effectContoroller, int fps); // �Փ˔���
	bool GetIsAvoidanceSuccess()const { return isAvoidanceSuccess; }; // ��𐬌��t���O��Ԃ�
private:
	bool isAvoidanceSuccess;	     // ��𐬌��t���O
	int avoidanceSuccessFrame;       // ��𐬌����̃t���[��
};