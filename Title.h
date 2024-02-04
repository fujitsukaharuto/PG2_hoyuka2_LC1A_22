#pragma once
#include <Novice.h>

class Title
{
public:
	Title();
	~Title();

	void Init();
	void Update(char* key);
	void Draw();

	bool GetIsGameChange() { return isGameChange_; }
	void SetIsGameChange(const bool& ok) { isGameChange_ = ok; }

private:

	bool isGameChange_;
	int cooltime_;

	int GH;
	int GH2;
	int GH3;

};