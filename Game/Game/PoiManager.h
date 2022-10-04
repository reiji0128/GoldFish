#pragma once
#include <vector>
#include "Math.h"
#include "Tag.h"

class PoiBase;

class PoiManager final
{
public:

    static void CreateInstance();

    static void DeleteInstance();

    static void Update(float deltaTime);

    static void Draw();

private:

    PoiManager();

    ~PoiManager();

    static PoiManager* mInstance;

    PoiBase* poiList[2];

};