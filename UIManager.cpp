#include "UImanager.h"

UIManager::UIManager()
{
    // 画像の読み込み
    excellentImgHandle = LoadGraph("IMG/Excellent.png");
    lifeImgHandle = LoadGraph("IMG/Life.png");
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
/// ゲームシーン描画
/// </summary>
/// <param name="isAvoidanceSuccess">回避成功フラグ</param>
void UIManager::DrawGameScene(bool isAvoidanceSuccess,int score, int playerLifeNum)
{
    // 回避成功フラグが立っていれば成功アクション描画
    if (isAvoidanceSuccess)
    {
        DrawExtendGraph(400, 50, 800, 250, excellentImgHandle,true);
    }

    // スコアの描画
    SetFontSize(SuccoreFontSize);
    DrawFormatString(900, 0, GetColor(0, 0, 0), "Score %d", score);

    // プレイヤーのライフ表示
    DrawExtendGraph(10, 10, 70, 58, lifeImgHandle, true);
    DrawFormatString(70, 10, GetColor(0, 0, 0), "×%d", playerLifeNum);
}

/// <summary>
/// リザルトシーン描画
/// </summary>
/// <param name="score">点数</param>
void UIManager::DrawResultScene(int score)
{
    // スコアの描画
    SetFontSize(ResultFontSize);
    DrawFormatString(350, 150, GetColor(0, 0, 0), "Score");
    DrawFormatString(370, 350, GetColor(0, 0, 0), "%d", score);
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

