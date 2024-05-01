#include "Collider.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="colliderRadius">���̔��a</param>
/// <param name="centorPos">���S���W</param>
Collider::Collider(float colliderRadius, VECTOR centorPos)
{
	this->colliderRadius = colliderRadius; // ���苅�ݒ�
	this->centerPos = centorPos;           // ���W�ݒ�
	this->isHit = false;                   // �Փ˃t���O������
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Collider::~Collider()
{

}

void Collider::UpdatePos(VECTOR setPos)
{
	centerPos = setPos;
}

void Collider::DrawCollider()
{
	DrawSphere3D(centerPos, colliderRadius, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}