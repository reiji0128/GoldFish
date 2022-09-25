#pragma once
#include <vector>
#include "Math.h"
#include "Tag.h"

/// <summary>
/// 当たり判定情報
/// </summary>
struct CollisionInfo
{
	Vector2 pos;
	Tag tag;
};

// 前方宣言
class Fish;
class RedFish;
class BlueFish;
class GoldFish;
class BlackFish;

class FishManager final
{
public:
	/// <summary>
	/// インスタンスの作成
	/// </summary>
	static void CreateInstance();

	/// <summary>
	/// インスタンスの削除
	/// </summary>
	static void DeleteInstance();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	static void Update(float deltaTime);

	/// <summary>
	/// 描画処理
	/// </summary>
	static void Draw();

	/// <summary>
	/// 金魚を格納するオブジェクトプールの作成
	/// </summary>
	/// <param name="redFishSize">生成する赤色の金魚の数</param>
	/// <param name="blueFishSize">生成する青色の金魚の数</param>
	/// <param name="goldFishSize">生成する金色の金魚の数</param>
	/// <param name="blackFishSize">生成する黒色の金魚の数</param>
	static void CreatePool(const int redFishSize,
					const int blueFishSize,
					const int goldFishSize,
	                const int blackFishSize);

	/// <summary>
	/// オブジェクトプールに金魚を追加
	/// </summary>
	/// <param name="addFish">追加する金魚</param>
	static void AddFish(Fish* addFish);

	/// <summary>
	/// オブジェクトプールの金魚の削除
	/// </summary>
	/// <param name="removeFish">削除する金魚</param>
	static void RemoveFish(Fish* removeFish);

	/// <summary>
	/// オブジェクトプールのすべての要素の削除
	/// </summary>
	static void RemoveAll();

// ゲッター //

	/// <summary>
	/// 当たり判定情報の取得
	/// </summary>
	/// <param name="i">取得する要素番号</param>
	/// <returns>当たり判定情報</returns>
	CollisionInfo GetCollisionInfo(int i);

private:
	/// <summary>
	/// シングルトン
	/// </summary>
	FishManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~FishManager();

	// マネージャーの実態
	static FishManager* mInstance;

	// 当たり判定情報
	CollisionInfo mCollisionInfo;

	// 金魚のオブジェクトプール
	std::vector<Fish*> mFishPool;

	RedFish* mRedFish;
	BlueFish* mBlueFish;
	GoldFish* mGoldFish;
	BlackFish* mBlackFish;
};
