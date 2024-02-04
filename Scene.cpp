#include "Scene.h"
#include "MathCalculation.h"

Scene::Scene()
{
	Init();
}

Scene::~Scene()
{
	delete title_;
	delete game_;
	delete result_;
}

void Scene::Init()
{
	title_ = new Title();
	game_ = new Game();
	result_ = new Result();

	tranceTime_ = 0;
	blackPos_ = { 0,0 };

	isTitle_ = true;
	isGame_ = false;
	isResult_ = false;
	isChange_ = false;
	isSceneTrance_ = false;
}

void Scene::Update(char* key)
{
	SceneChange();
	if (isTitle_ && tranceTime_ <= 0)
	{
		title_->Update(key);
	}
	if (isGame_ && tranceTime_ <= 0)
	{
		game_->Update(key);
	}
	if (isResult_ && tranceTime_ <= 0)
	{
		result_->Update(key);
	}
}

void Scene::Draw()
{
	if (isTitle_)
	{
		title_->Draw();
	}
	if (isGame_)
	{
		game_->Draw();
	}
	if (isResult_)
	{
		game_->Draw();
		result_->Draw(game_->GetIsClear());
	}
	if (isSceneTrance_)
	{
		Novice::DrawBox(int(blackPos_.x), int(blackPos_.y), 1280, 720, 0.0f, BLACK, kFillModeSolid);
	}
}

void Scene::SceneTrance()
{
	if (tranceTime_ < 60)
	{
		tranceTime_++;
	}
	Ease();
}

void Scene::Ease()
{
	float t = tranceTime_ / 60.0f;
	float E = 1.0f - (1.0f - t) * (1.0f - t);
	blackPos_ = Lerp({ 1280,0, }, { -1280,0 }, E);
}

void Scene::SceneChange()
{
	isSceneTrance_ = false;
	if (title_->GetIsGameChange())
	{
		isSceneTrance_ = true;
		SceneTrance();
		if (blackPos_.x <= 0)
		{
			isTitle_ = false;
			isGame_ = true;
		}
		if (tranceTime_ == 60)
		{
			title_->SetIsGameChange(false);
			tranceTime_ = 0;
		}
	}
	if (game_->GetIsResultChange())
	{

		isGame_ = false;

		game_->SetIsResultChange(false);
		isResult_ = true;

	}
	if (result_->GetIsTitleChange())
	{
		isSceneTrance_ = true;
		SceneTrance();
		if (blackPos_.x <= 0)
		{
			isResult_ = false;
			isTitle_ = true;
		}
		if (tranceTime_ == 60)
		{
			result_->SetIsTitleChange(false);
			game_->Restart();
			tranceTime_ = 0;
		}
	}
}
