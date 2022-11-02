#pragma once
#include "SceneBase.h"

class Exit : public SceneBase
{
public:
    Exit();

    ~Exit();

    SceneTag Updata(float deltaTime) override;

    void Input() override;

    void Draw() override;

private :
};

