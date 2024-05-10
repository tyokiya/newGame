#include "EffectController.h"

EffectController::EffectController()
{
	// フラグ初期化
	isPlayDamageEffect = false;
	// ダメージエフェクト読み込み
	LoadDivGraph("effect/DamageEffect.png", 10, 10, 1, 360, 360, damageEffect);
	// カウンター初期化
	damageEffectCnt = 0;
}

EffectController::~EffectController()
{

}

void EffectController::Update(int fps)
{
	//エフェクトカウント増加
	if (isPlayDamageEffect && fps % 5 == 0)
	{
		damageEffectCnt++;
		// index数を超えたら再生フラグを下ろす
		if(damageEffectCnt > DamageEffectCnt)
		{
			isPlayDamageEffect = false;
			damageEffectCnt = 0; // カウンター初期化
		}
	}
}

void EffectController::Draw()
{
	// 再生フラグが立っていれば描画
	if (isPlayDamageEffect)
	{
		DrawGraph(Player2DPosX, Player2DPosY, damageEffect[damageEffectCnt], TRUE);
	}
}

