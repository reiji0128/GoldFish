#pragma once
#include "PoiBase.h"

class PoiBlue : public PoiBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PoiBlue();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~PoiBlue();

    void Update(float deltaTime) override;
};