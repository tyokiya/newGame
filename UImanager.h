#pragma once
#include"DxLib.h"

const VECTOR TittleTextPos = VGet(400, 60, 0);
const VECTOR TurtrialTextPos = VGet(400, 650, 0);
const int TittleFontSize = 120;
const int TurtrialFontSize = 50;
const int CountDownFontSize = 120;

class UIManager
{
public:
    UIManager();
    ~UIManager();
    void DrawTittleSece();  // タイトルシーン描画
    bool Draw3CountDown(int fps); // 3秒カウント
private:
    int nowCount = 3; // カウントダウン時に使う変数
};