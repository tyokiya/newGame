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
	frame++; // �t���[������

	// int�^�̍ő�l�𒴂��Ȃ��悤��
	if (frame > 2000000000)
	{
		frame = 0;
	}
}