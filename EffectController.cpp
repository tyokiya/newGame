#include "EffectController.h"

EffectController::EffectController()
{
	// �t���O������
	isPlayDamageEffect = false;
	// �_���[�W�G�t�F�N�g�ǂݍ���
	LoadDivGraph("effect/DamageEffect.png", 10, 10, 1, 360, 360, damageEffect);
	// �J�E���^�[������
	damageEffectCnt = 0;
}

EffectController::~EffectController()
{

}

void EffectController::Update(int fps)
{
	//�G�t�F�N�g�J�E���g����
	if (isPlayDamageEffect && fps % 5 == 0)
	{
		damageEffectCnt++;
		// index���𒴂�����Đ��t���O�����낷
		if(damageEffectCnt > DamageEffectCnt)
		{
			isPlayDamageEffect = false;
			damageEffectCnt = 0; // �J�E���^�[������
		}
	}
}

void EffectController::Draw()
{
	// �Đ��t���O�������Ă���Ε`��
	if (isPlayDamageEffect)
	{
		DrawGraph(Player2DPosX, Player2DPosY, damageEffect[damageEffectCnt], TRUE);
	}
}

