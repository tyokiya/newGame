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
/// ÉXÉRÉAÇÃâ¡éZ
/// </summary>
void Score::AddSocre()
{
    nowScore += ScoreNum;
}