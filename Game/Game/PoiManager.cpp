#include "PoiManager.h"
#include "PoiBase.h"
#include "PoiRed.h"
#include "PoiBlue.h"

// PoiManager実体へのポインタ定義
PoiManager* PoiManager::mInstance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
PoiManager::PoiManager()
{
    mInstance = nullptr;
    poiList[0] = new PoiRed();
    poiList[1] = new PoiBlue();
}

/// <summary>
/// デストラクタ
/// </summary>
PoiManager::~PoiManager()
{
    for (auto list : poiList)
    {
        delete list;
    }
}

/// <summary>
/// ポイマネージャーの生成
/// </summary>
void PoiManager::CreateInstance()
{
    if (!mInstance)
    {
        mInstance = new PoiManager();
    }
}

/// <summary>
/// ポイマネージャーの削除
/// </summary>
void PoiManager::DeleteInstance()
{
    if (mInstance)
    {
        delete mInstance;
        mInstance = nullptr;
    }
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void PoiManager::Update(float deltaTime)
{
    for (auto list : mInstance->poiList)
    {
        list->Update(deltaTime);
    }
}

/// <summary>
/// 描画処理
/// </summary>
void PoiManager::Draw()
{
    for (auto list : mInstance->poiList)
    {
        list->Draw();
    }
}
