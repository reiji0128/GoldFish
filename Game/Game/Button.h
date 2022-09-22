#pragma once
#include "Math.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
static enum ButtonImgFileNum
{
	NONE_IMG = 0,
	START_IMG,
	EXIT_IMG,

	MAX_IMG_FILE_NUM,
};

// ��L��enum�N���X����
static const char* ButtonImgName[ButtonImgFileNum::MAX_IMG_FILE_NUM] =
{
	"img/None.png",
	"img/Start.png",
	"img/Exit.png",
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

