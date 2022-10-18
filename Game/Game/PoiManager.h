#pragma once

// 前方宣言
class PoiBase;

class PoiManager final
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

private:
    /// <summary>
    /// シングルトン
    /// </summary>
    PoiManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PoiManager();

    // ポイマネージャーの実体
    static PoiManager* mInstance;

    // ポイの配列
    PoiBase* poiList[2];

};