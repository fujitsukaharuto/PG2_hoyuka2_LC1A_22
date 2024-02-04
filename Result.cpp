#include <Novice.h>
#include "Result.h"

Result::Result()
{
	Init();
}

Result::~Result()
{
}

void Result::Init()
{
	isTitleChange_ = false;
	GH_ = Novice::LoadTexture("./Resource/UI_Space.png");
	ClearGH_=Novice::LoadTexture("./Resource/UI_clear.png");
	OverGH_=Novice::LoadTexture("./Resource/UI_over.png");
}

void Result::Update(char* key)
{
	if (cooltime_>0)
	{
		cooltime_--;
	}
	if (key[DIK_SPACE]&&cooltime_<=0)
	{
		isTitleChange_ = true;
		cooltime_ = 40;
	}
}

void Result::Draw(const bool& clear)
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000fa, kFillModeSolid);
	Novice::DrawQuad(551, 450, 721, 450, 551, 488, 721, 488, 0, 0, 162, 38, GH_, WHITE);
	if (clear)
	{
		Novice::DrawSprite(392, 256, ClearGH_, 1, 1, 0.0f, WHITE);
	}
	else
	{
		Novice::DrawSprite(435, 256, OverGH_, 1, 1, 0.0f, WHITE);
	}
}
