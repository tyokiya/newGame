#include "Collider.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="colliderRadius">球の半径</param>
/// <param name="centorPos">中心座標</param>
Collider::Collider(float colliderRadius, VECTOR centorPos)
{
	this->colliderRadius = colliderRadius; // 判定球設定
	this->centerPos = centorPos;           // 座標設定
	this->isHit = false;                   // 衝突フラグ初期化
}

/// <summary>
/// デストラクタ
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