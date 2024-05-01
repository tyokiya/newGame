#pragma once
#include "DxLib.h"

/// <summary>
/// �����蔻��N���X
/// </summary>
class Collider
{
public:
	Collider(float colliderRadius,VECTOR centorPos);            // �R���X�g���N�^
	~Collider();                                                // �f�X�g���N�^
	void UpdatePos(VECTOR setPos);                              // ���W�X�V
	VECTOR GetCenterPos()const { return centerPos; };           // ���W�Q�b�^�[
	float  GetColliderRasius()const { return colliderRadius; }; // ���a�Q�b�^�[
	bool GetisHit()const { return isHit; };                     // �Փ˃t���O�Q�b�^�[
	void DrawCollider();                                        // ����̕`��(�e�X�g�p)
private:
	VECTOR centerPos;     // �����蔻�苅�̒��S���W
	float colliderRadius; // �����蔻�苅�̔��a
	bool isHit;           // �Փ˃t���O	
};