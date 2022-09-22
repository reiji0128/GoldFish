#pragma once
#include "Math.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
static enum ButtonImgFileNum
{
	NONE_BUTTON_IMG = 0,
	START_BUTTON_IMG,
	EXIT_BUTTON_IMG,

	MAX_BUTTON_FILE_NUM,
};

// ��L��enum�N���X����
static const char* ButtonImgName[ButtonImgFileNum::MAX_BUTTON_FILE_NUM] =
{
	"img/Button/None.png",
	"img/Button/Start.png",
	"img/Button/Exit.png",
};

class Button
{
public:
	Button(const char* fileName);
	~Button();

	void Update(float deltaTime);

	void Draw();

private:
	Vector2 mPos;
	Vector2 mScale;
	int mImgHandle;
};

