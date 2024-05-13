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
        if (fadeCnt >= 0 && fadeCnt < 256)                    //�J�E���g��0~256�̎�
            SetDrawBright(fadeCnt, fadeCnt, fadeCnt);        //�i�X�����邭(�J�E���g= 0->255)
        if (fadeCnt >= 256 && fadeCnt < 400)                  //�J�E���g��256~400�̎�
            SetDrawBright(255, 255, 255);  //�ʏ�̖��邳
        if (fadeCnt >= 400 && fadeCnt < 400 + 256)              //�J�E���g��400~400+256�̎�
            SetDrawBright(255 - (fadeCnt - 400), 255 - (fadeCnt - 400), 255 - (fadeCnt - 400));//�i�X�Â�(�J�E���g= 255->0)
 
        DrawExtendGraph(0, 0, 1200, 800, fadeIMGHanlde, true); //�`��

        fadeCnt += FadeSpeed;                                  //�J�E���g�A�b�v

        //�Â��Ȃ�I�������I��
        if (fadeCnt >= 400 + 256)
        {
            isFadeStart = false; // �t���O������
            fadeCnt = 0;         // �J�E���g������
        }
    }
}