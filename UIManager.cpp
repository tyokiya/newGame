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
    DrawFormatString(TittleTextPos.x, TittleTextPos.y, GetColor(255, 255, 255), "tittle"); // �^�C�g��
}