#pragma once
#include "DxLib.h"

const int FadeSpeed = 5;

/// <summary>
/// �t�F�[�h�N���X
/// </summary>
class Fade
{
public:
    Fade();
    ~Fade();
    void Update();
    void SetIsFadeStart(bool setFlg) { isFadeStart = setFlg; };
    bool GetIsFadeStart()const { return isFadeStart; };
private:
    int fadeIMGHanlde;
    int fadeCnt;
    bool isFadeStart;  // �t�F�[�h�C���X�^�[�g�t���O
};

