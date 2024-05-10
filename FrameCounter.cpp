#include "FrameCounter.h"

FrameCounter::FrameCounter()
{
	Initialize();
}
FrameCounter::~FrameCounter()
{

}

void FrameCounter::Initialize()
{
	frame = 0;
}

void FrameCounter::Update()
{
	frame++; // フレーム増加

	// int型の最大値を超えないように
	if (frame > 2000000000)
	{
		frame = 0;
	}
}