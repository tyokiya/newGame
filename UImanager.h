#pragma once
#include"DxLib.h"

const VECTOR TittleTextPos = VGet(400, 60, 0);
const VECTOR TurtrialTextPos = VGet(400, 650, 0);
const int TittleFontSize = 120;
const int TurtrialFontSize = 50;
const int CountDownFontSize = 120;
const int SuccoreFontSize = 50;

class UIManager
{
public:
    UIManager();
    ~UIManager();
    void DrawTittleSece();                 // タイトルシーン描画
    void DrawGameScene(bool isAvoidanceSuccess,int score,int playerLifeNum); // ゲームシーン描画
    bool Draw3CountDown(int fps);          // 3秒カウント
private:
    int nowCount = 3;       // カウントダウン時に使う変数
    int excellentImgHandle; // エクセレント画像のハンドル
    int lifeImgHandle;      // ライフ画像のハンドル
};