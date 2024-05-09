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
    SetFontSize(TittleFontSize);
    DrawFormatString(TittleTextPos.x, TittleTextPos.y, GetColor(255, 0, 0), "tittle");              // タイトル

    SetFontSize(TurtrialFontSize);
    DrawFormatString(TurtrialTextPos.x, TurtrialTextPos.y, GetColor(255, 255, 0), "Spaceでジャンプ"); // チュートリアル
    DrawFormatString(TurtrialTextPos.x, TurtrialTextPos.y + TurtrialFontSize, GetColor(255, 255, 0), "Sキーでスタート");
}

/// <summary>
/// 3秒カウント
/// </summary>
/// <param name="fps">カウントするためのフレームを渡す</param>
bool UIManager::Draw3CountDown(int fps)
{
    // 1秒ごとにカウントダウン
    if(fps % 60 == 0)
    {
        nowCount--;
    }
    
    // フォントサイズ設定
    SetFontSize(CountDownFontSize);

    // カウント描画
    DrawFormatString(600, 400, GetColor(255, 0, 0), "%d", nowCount);

    // カウント終了時trueを返す
    if (nowCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}