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
    void DrawTittleSece();                 // �^�C�g���V�[���`��
    void DrawGameScene(bool isAvoidanceSuccess,int score,int playerLifeNum); // �Q�[���V�[���`��
    bool Draw3CountDown(int fps);          // 3�b�J�E���g
private:
    int nowCount = 3;       // �J�E���g�_�E�����Ɏg���ϐ�
    int excellentImgHandle; // �G�N�Z�����g�摜�̃n���h��
    int lifeImgHandle;      // ���C�t�摜�̃n���h��
};