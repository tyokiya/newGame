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
/// スコアの加算
/// </summary>
void Score::AddSocre()
{
    nowScore += ScoreNum;
}