#pragma once
#include "DxLib.h"

const int FadeSpeed = 1;
const int intMaxPalNum = 255; // �u�����h���[�h�̃}�b�N�X�p�����[�^

/// <summary>
/// �t�F�[�h�N���X
/// </summary>
class Fade
{
public:
    Fade();
    ~Fade();
    void FadeOut();
    void SetIsFadeOutStart(bool setFlg);
    bool GetIsFadeOutStart()const { return isFadeOutStart; };
private:
    int fadeIMGHanlde;
    int fadeCnt;
    bool isFadeOutStart;  // �t�F�[�h�C���X�^�[�g�t���O
};

