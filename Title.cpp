#include "Title.h"

Title::Title()
{
	Init();
}

Title::~Title()
{
}

void Title::Init()
{
	isGameChange_ = false;
	GH = Novice::LoadTexture("./Resource/sea2.png");
	GH2 = Novice::LoadTexture("./Resource/UI_title_abisu.png");
	GH3 = Novice::LoadTexture("./Resource/UI_Space.png");
	cooltime_ = 40;
}

void Title::Update(char* key)
{
	if (cooltime_>0)
	{
		cooltime_--;
	}
	if (key[DIK_SPACE] && cooltime_ <= 0)
	{
		isGameChange_ = true;
		cooltime_ = 40;
	}
}

void Title::Draw()
{
	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, GH, WHITE);
	Novice::DrawQuad(469, 200, 811, 200, 469, 304, 811, 304, 0, 0, 342, 104, GH2, WHITE);
	Novice::DrawQuad(551, 450, 721, 450, 551, 488, 721, 488, 0, 0, 162, 38, GH3, WHITE);
}
