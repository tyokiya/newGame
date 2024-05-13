#include "Fade.h"

Fade::Fade()
{
    fadeIMGHanlde = LoadGraph("IMG/FadePannel.jpg");
    fadeCnt = 0;
    isFadeStart = false;
}

Fade::~Fade()
{

}

void Fade::Update()
{
    if (isFadeStart)
    {
        if (fadeCnt >= 0 && fadeCnt < 256)                    //カウントが0~256の時
            SetDrawBright(fadeCnt, fadeCnt, fadeCnt);        //段々あかるく(カウント= 0->255)
        if (fadeCnt >= 256 && fadeCnt < 400)                  //カウントが256~400の時
            SetDrawBright(255, 255, 255);  //通常の明るさ
        if (fadeCnt >= 400 && fadeCnt < 400 + 256)              //カウントが400~400+256の時
            SetDrawBright(255 - (fadeCnt - 400), 255 - (fadeCnt - 400), 255 - (fadeCnt - 400));//段々暗く(カウント= 255->0)
 
        DrawExtendGraph(0, 0, 1200, 800, fadeIMGHanlde, true); //描画

        fadeCnt += FadeSpeed;                                  //カウントアップ

        //暗くなり終わったら終了
        if (fadeCnt >= 400 + 256)
        {
            isFadeStart = false; // フラグを下す
            fadeCnt = 0;         // カウント初期化
        }
    }
}