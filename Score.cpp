#include "DxLib.h"
#include "Score.h"

Score::Score()
{
    nowScore = 0;
}
Score::~Score()
{

}

/// <summary>
/// �X�R�A�̉��Z
/// </summary>
void Score::AddSocre()
{
    nowScore += ScoreNum;
}