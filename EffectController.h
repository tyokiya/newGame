#pragma once
#include "DxLib.h"
#define DamageEffectCnt 10

const float Player2DPosX = 100; // ��ʏ�ł̃v���C���[�̌Œ���W
const float Player2DPosY = 500;

class EffectController
{
public:
	EffectController();
	~EffectController();
	void Update(int fps);
	void Draw();
	void SetIsPlayDamageEffect(bool setFlg) { isPlayDamageEffect = setFlg; }; // �_���[�W�G�t�F�N�g�t���O�̃Z�b�^�[
private:
	bool isPlayDamageEffect;		   // �_���[�W�G�t�F�N�g�Đ��t���O
	int damageEffect[DamageEffectCnt]; // �_���[�W�G�t�F�N�g
	int damageEffectCnt;			   // �_���[�W�G�t�F�N�g�̃J�E���^�[
};
