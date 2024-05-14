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
	void DeleteObstacleObject(int index);		 // �w�肵����Q���I�u�W�F�N�g�̍폜
	void DeleteAllObstacleObject();			     // ���ׂĂ̏�Q���I�u�W�F�N�g�̍폜
	vector<Obstacle*> GetObstacleObject()const { return obstacleObjects; };
private:
	vector<Obstacle*> obstacleObjects; // ��Q���I�u�W�F�N�g�̃R���e�i	
};

