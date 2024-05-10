#pragma once
#include "DxLib.h"
#define DamageEffectCnt 10

const float Player2DPosX = 100; // 画面上でのプレイヤーの固定座標
const float Player2DPosY = 500;

class EffectController
{
public:
	EffectController();
	~EffectController();
	void Update(int fps);
	void Draw();
	void SetIsPlayDamageEffect(bool setFlg) { isPlayDamageEffect = setFlg; }; // ダメージエフェクトフラグのセッター
private:
	bool isPlayDamageEffect;		   // ダメージエフェクト再生フラグ
	int damageEffect[DamageEffectCnt]; // ダメージエフェクト
	int damageEffectCnt;			   // ダメージエフェクトのカウンター
};
