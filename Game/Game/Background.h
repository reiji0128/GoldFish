#pragma once
#include "Math.h"
#include "Image.h"

/// <summary>
/// 画像ファイルの順番.
/// </summary>
enum BgImgFileNum : unsigned short
{
	NoneBg = 0,      // 背景が何もない時.
	TitleBg,         // 背景がタイトルの時.
	TutorialBg,      // 背景がチュートリアルの時.
	PlayBg,          // 背景がプレイの時.
	ResultBg,        // 背景がリザルトの時.

	MaxBgNum,        // 背景画像の最大枚数.
};

// 上記のenumクラスの順番で画像ファイルパスを保存する変数.
static const char* BgImgName[BgImgFileNum::MaxBgNum] =
{
	"Img/Bg/None.png",       // 何もない時の画像ファイルパス.
	"Img/Bg/Title.png",      // タイトル時の画像ファイルパス.
	"Img/Bg/Tutorial.png",   // チュートリアル時の画像ファイルパス.
	"Img/Bg/Play.png",       // プレイ時の画像ファイルパス.
	"Img/Bg/Result.png",     // リザルト時の画像ファイルパス.
};

/// <summary>
/// 背景クラス.
/// </summary>
class Background : public Image
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Background(const char* fileName);

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Background();

	/// <summary>
	/// 更新関数.
	/// </summary>
 	void Updata(float deltaTime) override;

	/// <summary>
	/// 描画関数.
	/// </summary>
	void Draw() override;
};