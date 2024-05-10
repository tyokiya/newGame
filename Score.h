#pragma once
#include "DxLib.h"

const int ScoreNum = 100; // 加算点数

class Score
{
public:
    Score();
    ~Score();
    void AddSocre(); // スコアの加算
    int GetScore()const { return nowScore; }; // 点数のゲッター
private:
    int nowScore; // 現在の点数
};
