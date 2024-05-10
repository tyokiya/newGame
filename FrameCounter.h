#pragma once

class FrameCounter
{
public:
	FrameCounter();
	~FrameCounter();
	void Initialize();
	void Update();
	int GetFrame()const { return frame; };
private:
	int frame;
};
