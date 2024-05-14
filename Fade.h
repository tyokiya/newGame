#pragma once
#include "DxLib.h"

const int FadeSpeed = 1;
const int intMaxPalNum = 255; // ブレンドモードのマックスパラメータ

/// <summary>
/// フェードクラス
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
    bool isFadeOutStart;  // フェードインスタートフラグ
};

