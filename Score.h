#pragma once
#include "DxLib.h"

const int ScoreNum = 100; // ���Z�_��

class Score
{
public:
    Score();
    ~Score();
    void AddSocre(); // �X�R�A�̉��Z
    int GetScore()const { return nowScore; }; // �_���̃Q�b�^�[
private:
    int nowScore; // ���݂̓_��
};
