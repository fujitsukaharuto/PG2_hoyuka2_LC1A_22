#include "Gun.h"
#include <Novice.h>

Gun::Gun()
{
	Init();
}

Gun::~Gun()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		delete bullet[i];
	}
}


void Gun::Init()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet[i] = new Bullet();
	}
	coolTime_ = 30;
	GH_ = Novice::LoadTexture("./Resource/sakana__bullet.png");
}


void Gun::Update()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet[i]->Update();
	}
	if (coolTime_>0)
	{
		coolTime_--;
	}
}


void Gun::Draw()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet[i]->Draw(GH_);
	}
}


void Gun::Shot(const Vector2& pos)
{
	if (coolTime_<=0)
	{
		for (int i = 0; i < bulletNum_; i++)
		{
			if (!bullet[i]->GetIsLive())
			{
				bullet[i]->SetIsLive(true);
				bullet[i]->SetPos(pos);
				coolTime_ = 30;
				break;
			}
		}
	}
}

void Gun::Restart()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet[i]->Restart();
	}
	coolTime_ = 30;
}


int Gun::GetBulletNum()
{
	return bulletNum_;
}
Bullet** Gun::GetBullet()
{
	return bullet;
}
