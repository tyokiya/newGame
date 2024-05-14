#include "Fade.h"

Fade::Fade()
{
    fadeIMGHanlde = LoadGraph("IMG/FadePannel.jpg");
    fadeCnt = 0;
    isFadeOutStart = false;
}

Fade::~Fade()
{

}

/// <summary>
/// �t�F�[�h�A�E�g
/// </summary>
void Fade::FadeOut()
{
    if (isFadeOutStart)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeCnt);                                   // �u�����h���[�h��ύX
        DrawExtendGraph(0, 0, 1200, 800, fadeIMGHanlde, true);     // �`��
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		                                   //�u�����h���[�h���I�t
        fadeCnt -= FadeSpeed;                                  // �J�E���g�_�E��
    }

    // �Â��Ȃ�I�������I��
    if (fadeCnt <= 0)
    {
        isFadeOutStart = false; // �t���O������
    }
}

/// <summary>
/// �t�F�[�h�A�E�g�X�^�[�g�t���O�̃Z�b�^�[
/// </summary>
/// <param name="setFlg"></param>
void Fade::SetIsFadeOutStart(bool setFlg)
{
    isFadeOutStart = setFlg; // �t���O�𗧂Ă�
    fadeCnt = intMaxPalNum;  // �J�E���g������
}