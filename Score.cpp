#include "DxLib.h"
#include "Score.h"

Score::Score()
{

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