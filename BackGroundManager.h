#pragma once
#include "DxLib.h"
#include "vector"
#include "BackGroundObject.h"

class BackGroundObject;
using namespace std;

/// <summary>
/// �w�i�Ǘ��N���X
/// </summary>
class BackGroundManager
{
public:
	BackGroundManager();                       // �R���X�g���N�^
	~BackGroundManager();                      // �f�X�g���N�^
	void CreateBackGroudObj(float cameraPosX); // �w�i�I�u�W�F�N�g��������
	void Update();                             // �X�V����
	void Draw();                               // �`�揈��
private:
	vector<BackGroundObj*> backGoundObjects; // �w�i�I�u�W�F�N�g�̃R���e�i
	int BackImgHandle;                       // �w�i�摜�̃n���h��
};
