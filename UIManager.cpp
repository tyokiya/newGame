#include "UImanager.h"

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

/// <summary>
/// �^�C�g���V�[���`��
/// </summary>
void UIManager::DrawTittleSece()
{
    SetFontSize(TittleFontSize);
    DrawFormatString(TittleTextPos.x, TittleTextPos.y, GetColor(255, 0, 0), "tittle");              // �^�C�g��

    SetFontSize(TurtrialFontSize);
    DrawFormatString(TurtrialTextPos.x, TurtrialTextPos.y, GetColor(255, 255, 0), "Space�ŃW�����v"); // �`���[�g���A��
    DrawFormatString(TurtrialTextPos.x, TurtrialTextPos.y + TurtrialFontSize, GetColor(255, 255, 0), "S�L�[�ŃX�^�[�g");
}

/// <summary>
/// 3�b�J�E���g
/// </summary>
/// <param name="fps">�J�E���g���邽�߂̃t���[����n��</param>
bool UIManager::Draw3CountDown(int fps)
{
    // 1�b���ƂɃJ�E���g�_�E��
    if(fps % 60 == 0)
    {
        nowCount--;
    }
    
    // �t�H���g�T�C�Y�ݒ�
    SetFontSize(CountDownFontSize);

    // �J�E���g�`��
    DrawFormatString(600, 400, GetColor(255, 0, 0), "%d", nowCount);

    // �J�E���g�I����true��Ԃ�
    if (nowCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}