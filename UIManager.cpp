#include "UImanager.h"

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

/// <summary>
/// タイトルシーン描画
/// </summary>
void UIManager::DrawTittleSece()
{
    DrawFormatString(TittleTextPos.x, TittleTextPos.y, GetColor(255, 255, 255), "tittle"); // タイトル
}