#include "Fade.h"

Fade::Fade()
{
    fadeIMGHanlde = LoadGraph("IMG/FadePannel.jpg");
    fadeCnt = 0;
    isFadeOutStart = false;
}

Fade::~Fade()
{

}

/// <summary>
/// フェードアウト
/// </summary>
void Fade::FadeOut()
{
    if (isFadeOutStart)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeCnt);                                   // ブレンドモードを変更
        DrawExtendGraph(0, 0, 1200, 800, fadeIMGHanlde, true);     // 描画
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		                                   //ブレンドモードをオフ
        fadeCnt -= FadeSpeed;                                  // カウントダウン
    }

    // 暗くなり終わったら終了
    if (fadeCnt <= 0)
    {
        isFadeOutStart = false; // フラグを下す
    }
}

/// <summary>
/// フェードアウトスタートフラグのセッター
/// </summary>
/// <param name="setFlg"></param>
void Fade::SetIsFadeOutStart(bool setFlg)
{
    isFadeOutStart = setFlg; // フラグを立てる
    fadeCnt = intMaxPalNum;  // カウント初期化
}