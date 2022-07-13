#pragma once
#include "Math.h"

class BaseObject
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	BaseObject();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BaseObject();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void Update(float deltaTime);

	/// <summary>
	/// オブジェクトの更新処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	virtual void UpdateObject(float deltaTime);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

// ゲッター //

	/// <summary>
	/// 座標の取得
	/// </summary>
	/// <returns>座標</returns>
	const Vector2& GetPosition() const { return mPosition; }

	/// <summary>
	/// スケールの取得
	/// </summary>
	/// <returns>スケール</returns>
	const Vector2& GetScale() const { return mScale; }

	/// <summary>
	/// 角度の取得
	/// </summary>
	/// <returns>角度</returns>
	const float& GetAngle() const { return mAngle; }

// セッター //

	/// <summary>
	/// 座標のセット
	/// </summary>
	/// <param name="position">セットする座標</param>
	void SetPosition(const Vector2& position) { mPosition = position; }

	/// <summary>
	/// スケールのセット
	/// </summary>
	/// <param name="scale">セットするスケール</param>
	void SetScale(const Vector2& scale) { mScale = scale; }

	/// <summary>
	/// 角度のセット
	/// </summary>
	/// <param name="angle">セットする角度</param>
	void SetAngle(const float& angle) { mAngle = angle; }

private:
	// 座標
	Vector2 mPosition;

	// スケール
	Vector2 mScale;

	// 角度
	float mAngle;
};