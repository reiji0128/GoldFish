#include "PoiManager.h"
#include "PoiBase.h"
#include "PoiRed.h"
#include "PoiBlue.h"

PoiManager* PoiManager::mInstance = nullptr;

PoiManager::PoiManager()
{
    mInstance = nullptr;
    poiList[0] = new PoiRed();
    poiList[1] = new PoiBlue();
}

PoiManager::~PoiManager()
{
    delete [] poiList;
}

void PoiManager::CreateInstance()
{
    if (!mInstance)
    {
        mInstance = new PoiManager;
    }
}

void PoiManager::DeleteInstance()
{
    if (mInstance)
    {
        delete mInstance;
        mInstance = nullptr;
    }
}

void PoiManager::Update(float deltaTime)
{
    for (auto list : mInstance->poiList)
    {
        list->Update(deltaTime);
    }
}

void PoiManager::Draw()
{
    for (auto list : mInstance->poiList)
    {
        list->Draw();
    }
}
