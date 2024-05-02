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
	void CreateObstacleObject(float cameraPosX); // ��Q���I�u�W�F�N�g����
	void Update(float cameraPosX);
	void Draw();
private:
	vector<Obstacle*> obstacleObjects; // ��Q���I�u�W�F�N�g�̃R���e�i	
};

