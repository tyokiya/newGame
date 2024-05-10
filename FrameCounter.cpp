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
	frame++; // ƒtƒŒ[ƒ€‘‰Á

	// intŒ^‚ÌÅ‘å’l‚ð’´‚¦‚È‚¢‚æ‚¤‚É
	if (frame > 2000000000)
	{
		frame = 0;
	}
}