#pragma once
#include "PoiBase.h"

class PoiBlue : public PoiBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PoiBlue();

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~PoiBlue();

    void Update(float deltaTime) override;
};