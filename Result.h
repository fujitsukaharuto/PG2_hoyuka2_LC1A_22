#pragma once


class Result
{
public:
	Result();
	~Result();

	void Init();
	void Update(char* key);
	void Draw(const bool& clear);

	bool GetIsTitleChange() { return isTitleChange_; }
	void SetIsTitleChange(const bool& ok) { isTitleChange_ = ok; }

private:

	bool isTitleChange_;
	int cooltime_;

	int GH_;
	int ClearGH_;
	int OverGH_;
};