#pragma once

//------------------------------
// ここにゲームプレイ中に必要なヘッダーをインクルードしてください.


/// <summary>
/// ゲームマネージャークラス.
/// </summary>
class GameManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	GameManager();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~GameManager();

	/// <summary>
	/// 更新関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	void Update(float deltaTime);

	/// <summary>
	/// 描画関数.
	/// </summary>
	void Draw();

private:
};

