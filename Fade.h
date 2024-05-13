#pragma once
#include "DxLib.h"

const int FadeSpeed = 5;

/// <summary>
/// フェードクラス
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
    bool isFadeStart;  // フェードインスタートフラグ
};

