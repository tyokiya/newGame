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
    void DrawTittleSece();  // �^�C�g���V�[���`��
    bool Draw3CountDown(int fps); // 3�b�J�E���g
private:
    int nowCount = 3; // �J�E���g�_�E�����Ɏg���ϐ�
};